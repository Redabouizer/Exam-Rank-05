#pragma once

#include <iostream>

class vect2
{
    private :
        int x;
        int y;
    public :
        vect2(): x(0), y(0){}
        vect2(int x , int y): x(x), y(y){}
        vect2(const vect2& other ) : x(other.x), y(other.y){}

        vect2& operator=(const vect2& other )
        {
            if(*this != other )
            {
                x = other.x ;
                y = other.y;
            }
            return *this;
        }

        int& operator[](int i)
        {
            return (i == 0  ? x : y);
        }

        const int& operator[](int i) const
        {
            return (i == 0  ? x : y);
        }

        vect2 operator++()
        {
            vect2 tmp = *this;
            x++;
            y++;
            return *this;
        }

        vect2& operator++(int)
        {
            x++;
            y++;
            return *this;
        }

        vect2 operator--()
        {
            vect2 tmp = *this;
            x--;
            y--;
            return *this;
        }

        vect2& operator--(int)
        {
            x--;
            y--;
            return *this;
        }

        vect2& operator+=(const vect2& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        vect2& operator-=(const vect2& other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        vect2 operator+(const vect2& other) const
        {
            return vect2(x + other.x, y +  other.y);
        }

        vect2 operator-(const vect2& other) const
        {
            return vect2(x - other.x, y -  other.y);
        }

        vect2 operator*(int i) const
        {
            return vect2(x  * i , y  * i);
        }

        friend vect2 operator*(int i, const vect2& other)
        {
            return vect2(other.x  * i , other.y  * i);
        }

        vect2& operator*=(int i)
        {
            x *= i;
            y *= i;
            return *this;
        }

        vect2 operator-() const
        {
            return vect2(-x  , -y);
        }
























        friend std::ostream& operator<<(std::ostream& os , const vect2& other )
        {
            os << "{" << other[0] << ", " << other[1] << "}";
            return os;
        }

        bool operator!=(const vect2& other )
        {
            return (x != other.x || y != other.y);
        }
        bool operator==(const vect2& other )
        {
            return (x == other.x || y == other.y);
        }

        ~vect2(){}
};