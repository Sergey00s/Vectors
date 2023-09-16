#include "Vector.hpp"



Vector::Vector()
{
    data = std::vector<float>(3, 0);
}

Vector::Vector(float x, float y, float z)
{
    data = std::vector<float>(3, 0);
    data[0] = x;
    data[1] = y;
    data[2] = z;
}

Vector::Vector(float x, float y)
{
    data = std::vector<float>(2, 0);
    data[0] = x;
    data[1] = y;
}

Vector::Vector(std::vector<float> data)
{
    this->data = data;
}

Vector::Vector(std::initializer_list<float> data)
{
    this->data = std::vector<float>(data);
}

Vector::Vector(int size)
{
    data = std::vector<float>(size, 0);
}

Vector::Vector(const Vector &v)
{
    data = v.data;
}

Vector &Vector::operator=(const Vector &v)
{
    data = v.data;
    return *this;
}

Vector::~Vector()
{
     //std::cout << "Vector destructor called" << std::endl;
}





// Accessors


const float &Vector::operator[](int i) const
{
    return data[i];
}

float &Vector::operator[](int i)
{
    return data[i];
}

// Operators

Vector Vector::operator+(const Vector &v) const
{
    Vector result = *this;
    for (int i = 0; i < data.size(); i++)
    {
        result[i] += v[i];
    }
    return result;
}

Vector Vector::operator-() 
{
    Vector result = *this;
    for (int i = 0; i < data.size(); i++)
    {
        result[i] = -result[i];
    }
    return result;
}

Vector Vector::operator+() const
{
    return *this;
}

Vector Vector::operator-(const Vector &v) const
{
    Vector result = *this;
    for (int i = 0; i < data.size(); i++)
    {
        result[i] -= v[i];
    }
    return result;
}

Vector Vector::operator*(float c) const
{
    Vector result = *this;
    for (int i = 0; i < data.size(); i++)
    {
        result[i] *= c;
    }
    return result;
}

Vector Vector::operator*(const Vector &v) const
{
    Vector result = *this;
    for (int i = 0; i < data.size(); i++)
    {
        result[i] *= v[i];
    }
    return result;
}

Vector Vector::operator/(float c) const
{
    Vector result = *this;
    for (int i = 0; i < data.size(); i++)
    {
        result[i] /= c;
    }
    return result;
}

Vector &Vector::operator+=(const Vector &v)
{
    for (int i = 0; i < data.size(); i++)
    {
        data[i] += v[i];
    }
    return *this;
}

Vector &Vector::operator-=(const Vector &v)
{
    for (int i = 0; i < data.size(); i++)
    {
        data[i] -= v[i];
    }
    return *this;
}


Vector &Vector::operator*=(float c)
{
    for (int i = 0; i < data.size(); i++)
    {
        data[i] *= c;
    }
    return *this;
}

Vector &Vector::operator/=(float c)
{
    for (int i = 0; i < data.size(); i++)
    {
        data[i] /= c;
    }
    return *this;
}

bool Vector::operator==(const Vector &v) const
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] != v[i])
        {
            return false;
        }
    }
    return true;
}


bool Vector::operator!=(const Vector &v) const
{
    return !(*this == v);
}

float Vector::dot(const Vector &v) const
{
    float result = 0;
    for (int i = 0; i < data.size(); i++)
    {
        result += data[i] * v[i];
    }
    return result;
}

Vector Vector::cross(const Vector &v) const
{
    Vector result = Vector(0, 0, 0);

    if (data.size() != 3 || v.data.size() != 3)
    {
        std::cerr << "Cross product is only defined for 3D vectors" << std::endl;
        abort();
    }
    result[0] = data[1] * v[2] - data[2] * v[1];
    result[1] = data[2] * v[0] - data[0] * v[2];
    result[2] = data[0] * v[1] - data[1] * v[0];
    return result;
}


float Vector::norm() const
{
    float result = 0;
    for (int i = 0; i < data.size(); i++)
    {
        result += data[i] * data[i];
    }
    return sqrt(result);
}

float Vector::distance(const Vector &v) const
{
    return (*this - v).norm();
}

Vector Vector::normalize() const
{
    return *this / norm();
}



// Friends

std::ostream &operator<<(std::ostream &os, const Vector &v)
{
    os << "(";
    for (int i = 0; i < v.data.size(); i++)
    {
        os << v.data[i];
        if (i != v.data.size() - 1)
        {
            os << ", ";
        }
    }
    os << ")";
    return os;
}

std::istream &operator>>(std::istream &is, Vector &v)
{
    for (int i = 0; i < v.data.size(); i++)
    {
        is >> v.data[i];
    }
    return is;
}



// Getters
std::vector<float> Vector::getData() const
{
    return data;
}

