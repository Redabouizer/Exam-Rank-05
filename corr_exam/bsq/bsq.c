#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct {
    int y, x, size;
} square;

int min3(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    else if (b <= a && b <= c) return b;
    return c;
}

int _strlen(char *str) {
    int i = 0;
    while (str[i]) i++;
    return i;
}

int read_header(FILE *f, int *hgh, char *empty, char *obs, char *full) {
    if (fscanf(f, "%d %c %c %c\n", hgh, empty, obs, full) != 4)
        return fprintf(stdout, "map error\n"), -1;
    if (*empty == *obs || *empty == *full || *obs == *full)
        return fprintf(stdout, "map error\n"), -1;
    return 0;
}

char **read_map(FILE *f, int hgh, int *wdth)
{
    char **map = calloc(hgh, sizeof(*map));
    size_t len = 0;
    *wdth = 0;

    for (int i = 0; i < hgh; i++) {
        if (getline(&map[i], &len, f) < 0)
            return NULL;
        int l = _strlen(map[i]);
        if (map[i][l-1] == '\n')
            map[i][--l] = '\0';
        if (*wdth == 0)
            *wdth = l;
        if (l != *wdth)
            return NULL;
    }
    return map;
}

int **alloc_db(int hgh, int wdth) {
    int **db = calloc(hgh+1, sizeof(*db));
    for (int i = 0; i <= hgh; i++)
        db[i] = calloc(wdth+1, sizeof(**db));
    return db;
}

void fill_square(char **map, square sq, char full) {
    for (int i = sq.y - sq.size + 1; i <= sq.y; i++)
        for (int j = sq.x - sq.size + 1; j <= sq.x; j++)
            map[i][j] = full;
}

void print_map(char **map, int hgh) {
    for (int i = 0; i < hgh; i++)
        printf("%s\n", map[i]);
}

void free_map(char **map, int hgh) {
    for (int i = 0; i < hgh; i++)
        free(map[i]);
    free(map);
}

void free_db(int **db, int hgh) {
    for (int i = 0; i <= hgh; i++)
        free(db[i]);
    free(db);
}

int main(int ac, char **av) {
    FILE *f = ac > 1 ? fopen(av[1], "r") : stdin;
    if (!f)
        return (fprintf(stdout, "file error\n"), 1);

    int hgh, wdth;
    char empty, obs, full;
    
    if (read_header(f, &hgh, &empty, &obs, &full) < 0)
        return 1;

    char **map = read_map(f, hgh, &wdth);
    if (!map)
        return fprintf(stdout, "map error\n"), 1;
    
    if (f != stdin)
        fclose(f);

    int **db = alloc_db(hgh, wdth);
    square sq = {0, 0, 0};

    for (int i = 0; i < hgh; i++) {
        for (int j = 0; j < wdth; j++)
        {
            if (map[i][j] == empty)
            {
                db[i+1][j+1] = 1 + min3(db[i][j+1], db[i+1][j], db[i][j]);
                if (db[i+1][j+1] > sq.size)
                    sq = (square){i, j, db[i+1][j+1]};
            }
            else if (map[i][j] != obs) {
                free_map(map, hgh);
                free_db(db, hgh);
                return fprintf(stdout, "map error\n"), 1;
            }
        }
    }

    fill_square(map, sq, full);
    print_map(map, hgh);

    free_map(map, hgh);
    free_db(db, hgh);

    return 0;
}