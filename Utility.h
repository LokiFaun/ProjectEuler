#pragma once

#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <sstream>
#include <vector>
#include <exception>
#include <algorithm>

template<typename T>
std::string to_string(T value)
{
    std::stringstream stream;
    stream << value;
    return stream.str();
}

template<typename T>
int from_string(std::string input)
{
    std::stringstream stream;
    stream << input;
    T value;
    if ((stream >> value).fail())
    {
        throw std::bad_cast();
    }
    return value;
}

template<typename T>
bool is_prime(T number)
{
    if (number < 2) { return false; }
    if (number == 2) { return true; }
    if (number % 2 == 0) { return false; }
    for (T i = 2; i <= sqrt(number) + 1; i++)
    {
        if (number % i == 0) { return false; }
    }
    return true;
}

template <typename T>
bool is_even(T value)
{
    return value % 2 == 0;
}

template <typename T>
bool is_neven(T value)
{
    return !is_even(value);
}

template <typename T>
std::vector<T> generate_range(T min, T max)
{
    class sequence
    {
    private:
        T value;
    public:
        sequence(T init) : value(init) { }
        T operator() () { return value++; }
    };
    std::vector<T> range;
    std::generate_n(std::back_inserter(range), max, sequence(min));
    return range;
}

#endif // UTILITY_H
