#pragma once

#include <cmath>
#include <iostream>
#include <vector>

class Vector
{
    private:
        std::vector<float> data;

    public:
        Vector();
        Vector(float x, float y);
        Vector(float x, float y, float z);
        Vector(std::vector<float> data);
        Vector(std::initializer_list<float> data);
        Vector(int size);
        Vector(const Vector &v);
        Vector &operator=(const Vector &v);
        ~Vector();


    public:
        const float &operator[](int i) const;
        float &operator[](int i);
        Vector operator+(const Vector &v) const;
        Vector operator-(const Vector &v) const;
        Vector operator*(float c) const;
        Vector operator*(const Vector &v) const;
        Vector operator/(float c) const;
        Vector operator-() const;
        Vector &operator+=(const Vector &v);
        Vector &operator-=(const Vector &v);
        Vector &operator*=(float c);
        Vector &operator/=(float c);
        Vector &operator++();
        Vector operator++(int);
        Vector &operator--();
        Vector operator--(int);
        Vector operator+() const;
        Vector operator-() ;
        bool operator==(const Vector &v) const;
        bool operator!=(const Vector &v) const;
        float dot(const Vector &v) const;
        Vector cross(const Vector &v) const;
        float norm() const;
        float distance(const Vector &v) const;
        Vector normalize() const;

    public:
        friend std::ostream &operator<<(std::ostream &os, const Vector &v);
        friend std::istream &operator>>(std::istream &is, Vector &v);

    public:
       std::vector<float> getData() const;

};