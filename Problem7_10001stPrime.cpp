#include "ProjectEuler.h"
#include "Utility.h"

long long Problem_7_10001stPrime()
{
    long long counter = 0;
    long long countEnd = 10001;
    for (long long i = 2; i < std::numeric_limits<long long>::max(); i++)
    {
        if (is_prime(i))
        {
            counter++;
        }
        if (counter == countEnd)
        {
            return i;
        }
    }
    return 0;
}

