#pragma once

#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <sstream>
#include <vector>
#include <exception>
#include <algorithm>
#include <iostream>

template<typename T>
T from_string(std::string input)
{
    if (input.empty()) { return 0; }
    std::stringstream stream;
    stream << input;
    T value;
    if ((stream >> value).fail())
    {
        std::cerr << "bad_cast: " << input;
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

class big_integer
{
private:
    std::string m_Value;
public:
    big_integer() : m_Value("") { }
    big_integer(std::string const & value) : m_Value(value) { }
    big_integer(big_integer const & rhs) : m_Value(rhs.value()) { }
    big_integer(long long value) : m_Value(std::to_string(value)) { }
    big_integer operator + (big_integer const & rhs)
    {
        const std::string & big = rhs.size() > size() ? rhs.value() : value();
        const std::string & small = rhs.size() > size() ? value() : rhs.value();

        std::string bigSum = '0' + big;
        auto smallIter = small.rbegin();
        auto sumIter = bigSum.rbegin();

        int carry = 0;
        while (smallIter != small.rend())
        {
            int sum = from_string<int>(std::to_string(*smallIter)) + from_string<int>(std::to_string(*sumIter)) + carry;
            carry = sum > 9 ? 1 : 0;
            if (carry == 1)
            {
                sum -= 10;
            }
            *sumIter = std::to_string(sum)[0];
            sumIter++;
            smallIter++;
        }
        if (carry == 1)
        {
            *sumIter = std::to_string(from_string<int>(std::to_string(*sumIter)) / 10)[0];
        }
        if (bigSum[0] == '0')
        {
            bigSum.erase(0, 1);
        }
        return big_integer(bigSum);
    }

    const std::string & value() const { return m_Value; }
    size_t size() const { return m_Value.size(); }
};

#endif // UTILITY_H
