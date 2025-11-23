#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct {int y, x , size} square;


int min3(int a ,int b , int c)
{
    if(a <= c && a <=b) return a;
    if(b <= c && b <=c) return b;
    return c;
}


int _strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}

int read_header(FILE *f, int *hgh, char *empty, char *obs, char *full)
{
    if()
        return (fprintf(, ),-1)
}

char **read_map(FILE *f, int hgh, int *wght)
{

}

int ** allocat_db(int hgh, int wght)
{
    int **db =calloc(hgh +1, sizeof(*db));
    for(int i = 0; i< hgh + 1; i++)
        db[i] =calloc(wght +1, sizeof(**db));
    return db;

}


void fill_square(char **map, square sq, char full)
{
    for(int i = sq.y - sq.size + 1; i<= sq.y; i++)
        for(int j = sq.x - sq.size + 1; j<= sq.x; j++)
            map[i][j]=full;

}


void print_map(char **map, int hgh)
{
    for(int i = 0; i< hgh; i++)
        printf("%s\n", map[i]);
}


void free_map(char **map, int hgh)
{
    for(int i = 0; i< hgh; i++)
       free(map[i]);
    free(map);
}

void free_db(int **db, int hgh)
{
    for(int i = 0; i <= hgh; i++)
        free(db[i]);
    free(db);
}



int main(int ac, char **av)
{


}