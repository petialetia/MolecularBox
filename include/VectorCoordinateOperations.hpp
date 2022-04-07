#ifndef VECTOR_COORDINATE_OPERATIONS_HPP
#define VECTOR_COORDINATE_OPERATIONS_HPP

#include <vector>
#include <cassert>

template <typename T>
void TermByTermCompoundAddition(std::vector<T>& first, const std::vector<T>& second)
{
    assert(first.size() == second.size());
    for (size_t i = 0; i < first.size(); i++)
    {
        first[i] += second[i];
    }
}

template <typename T>
std::vector<T> TermByTermAddition(std::vector<T> first, const std::vector<T>& second)
{
    TermByTermCompoundAddition(first, second);
    return first;
}

template <typename T>
void TermByTermCompoundMultiplication(std::vector<T>& first, const T second)
{
    for (size_t i = 0; i < first.size(); i++)
    {
        first[i] *= second;
    }
}

template <typename T>
std::vector<T> TermByTermMultiplication(std::vector<T> first, const T second)
{
    TermByTermCompoundMultiplication(first, second);
    return first;
}

template <typename T>
std::vector<T> TermByTermMultiplication(const T first, const std::vector<T>& second)
{
    return TermByTermMultiplication(second, first);
}

#endif /* VECTOR_COORDINATE_OPERATIONS_HPP */