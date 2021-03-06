#ifndef COORDINATES_HPP
#define COORDINATES_HPP

#include "VectorCoordinateOperations.hpp"

#include <vector>
#include <initializer_list>
#include <cmath>

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


    const T& operator[](const size_t index) const
    {
        return std::vector<T>::operator[](index);
    }

    T& operator[](const size_t index)
    {
        return std::vector<T>::operator[](index);
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

template<typename T>
T CountLength(const Coordinates<T>& vector)
{
    T sum = 0;

    for (size_t i = 0; i < vector.size(); i++)
    {
        sum += vector[i] * vector[i];
    }

    return std::sqrt(sum);
}

template<typename T>
T CountDotProduct(const Coordinates<T>& first_vector, const Coordinates<T>& second_vector)
{
    assert(first_vector.size() == second_vector.size());

    T dot_product = 0;

    for (size_t i = 0; i < first_vector.size(); i++)
    {
        dot_product += first_vector[i] * second_vector[i];
    }

    return dot_product;
}

template<typename T>
double FindVectorsCos(const Coordinates<T>& first_vector, const Coordinates<T>& second_vector)
{
    assert(CountLength(first_vector)  != 0);
    assert(CountLength(second_vector) != 0);

    return CountDotProduct(first_vector, second_vector) / (CountLength(first_vector) * CountLength(second_vector));
}

template<typename T> 
Coordinates<T> GetUnitVector(const Coordinates<T>& direction)
{
    return direction / CountLength(direction);
}

template<typename T>
Coordinates<T> CountProjection(const Coordinates<T>& projected, const Coordinates<T>& vector_to_be_projected_onto)
{
    if (CountLength(projected) == 0)
    {
        return projected;
    } 


    return CountLength(projected) * FindVectorsCos(projected, vector_to_be_projected_onto) * GetUnitVector(vector_to_be_projected_onto);
}

template<typename T>
bool IsCodirectional(const Coordinates<T>& first_vector, const Coordinates<T>& second_vector)
{
    assert(first_vector.size() == second_vector.size());
    assert(!first_vector.empty());

    return first_vector / CountLength(first_vector) == second_vector / CountLength(second_vector);
}

#endif /* COORDINATES_HPP */
