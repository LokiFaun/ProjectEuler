#include "ProjectEuler.h"
#include "Utility.h"

long long Problem_10_SummationOfPrimes()
{
    std::vector<long long> numbers;
    std::vector<long long> range = generate_range<long long>(0, 2000000);
    auto isPrime = [&numbers](long long i)
    {
        if (is_prime(i))
        {
            numbers.push_back(i);
        }
    };
    std::for_each(std::begin(range), std::end(range), isPrime);
    return std::accumulate(std::begin(numbers), std::end(numbers), static_cast<long long>(0));
}
