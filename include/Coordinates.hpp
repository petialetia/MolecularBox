#ifndef COORDINATES_HPP
#define COORDINATES_HPP

#include "UsingAliasMolecularBox.hpp"
#include "VectorCoordinateOperations.hpp"

#include <vector>
#include <initializer_list>

template<typename T>
class Coordinates: public std::vector<T>
{
  public:
    explicit Coordinates() = default;

    explicit Coordinates(std::initializer_list<T> list) : 
        std::vector<T>(list)
    {
    }

    explicit Coordinates(std::vector<T> vector) : std::vector<T>(vector)
    {
    }

    template<typename OtherT>
    explicit Coordinates(const Coordinates<OtherT>& other)
    {
        for (size_t i = 0; i < other.size(); i++)
        {
            std::vector<T>::push_back(static_cast<T>(other[i]));
        }
    }


    Coordinates& operator+=(const Coordinates& other)
    {
        TermByTermCompoundAddition(*this, other);
        return *this;
    }

    Coordinates& operator-=(const Coordinates& other)
    {
        TermByTermCompoundSubtraction(*this, other);
        return *this;
    }

    Coordinates& operator*=(const Coordinates& other)
    {
        TermByTermCompoundMultiplication(*this, other);
        return *this;
    }

    Coordinates& operator*=(const T other)
    {
        TermByTermCompoundMultiplication(*this, other);
        return *this;
    }

    Coordinates& operator/=(const Coordinates& other)
    {
        TermByTermCompoundDivision(*this, other);
        return *this;
    }

    Coordinates& operator/=(const T other)
    {
        TermByTermCompoundDivision(*this, other);
        return *this;
    }
};

template<typename T>
Coordinates<T> operator+(Coordinates<T> first, const Coordinates<T>& second)
{
    first+= second;
    return first;
}

template<typename T>
Coordinates<T> operator-(Coordinates<T> first, const Coordinates<T>& second)
{
    first-= second;
    return first;
}

template<typename T>
Coordinates<T> operator*(Coordinates<T> first, const Coordinates<T>& second)
{
    first*= second;
    return first;
}

template<typename T>
Coordinates<T> operator*(Coordinates<T> first, const T second)
{
    first*= second;
    return first;
}

template<typename T>
Coordinates<T> operator*(const T first, Coordinates<T> second)
{
    second*= first;
    return second;
}

template<typename T>
Coordinates<T> operator/(Coordinates<T> first, const Coordinates<T>& second)
{
    first/= second;
    return first;
}

template<typename T>
Coordinates<T> operator/(Coordinates<T> first, const T second)
{
    first/= second;
    return first;
}

#endif /* COORDINATES_HPP */
