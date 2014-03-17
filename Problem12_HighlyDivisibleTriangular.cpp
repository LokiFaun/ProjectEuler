#include "ProjectEuler.h"
#include "Utility.h"

long long GetNumberDivisors(long long number)
{
    long long counter = 0;
    for (long long j = 1; j < sqrt(number); j++)
    {
        if (number % j == 0)
        {
            counter += 2;
        }
        if (pow(sqrt(number), 2) == number)
        {
            counter--;
        }
    }
    return counter;
}

long long Problem_12_HighlyDivisibleTriangularNumber()
{
    const size_t nrDivisors = 500;
    for (long long i = 1;; i++)
    {
        std::vector<long long> numbers = generate_range(0LL, i);
        const long long triangular = std::accumulate(std::begin(numbers), std::end(numbers), 0);
        if (GetNumberDivisors(triangular) >= nrDivisors)
        {
            return triangular;
        }
    }
    return 0;
}
