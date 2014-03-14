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
