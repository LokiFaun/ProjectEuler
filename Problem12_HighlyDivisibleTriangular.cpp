#include "ProjectEuler.h"
#include "Utility.h"

long long CreateTriangular(long long number)
{
    long long triangular = 0;
    for (long long i = 1; i <= number; i++)
    {
        triangular += i;
    }
    return triangular;
}

std::vector<long long> GetDivisors(long long number)
{
    std::vector<long long> divisors;
    for (long long i = 1; i < number / 2; i++)
    {
        if (number % i == 0)
        {
            divisors.push_back(i);
        }
    }
    return divisors;
}

long long Problem_12_HighlyDivisibleTriangularNumber()
{
    const size_t nrDivisors = 5;
    for (long long i = 1;; i++)
    {
        const long long triangular = CreateTriangular(i);
        const std::vector<long long> divisors = GetDivisors(triangular);
        if (divisors.size() == nrDivisors)
        {
            return triangular;
        }
    }
    return 0;
}
