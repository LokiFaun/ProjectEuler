#include "ProjectEuler.h"
#include <cmath>
#include <limits>

long long Problem_5_SmallestMultiple()
{
    long long range = 20;
    long long max = std::numeric_limits<long long>::max();
    for (long long i = static_cast<long long>(std::pow(range, 2)); i < max; i++)
    {
        bool isMultiple = true;
        for (long long j = 1; j <= range; j++)
        {
            if (i % j != 0)
            {
                isMultiple &= false;
            }
        }
        if (isMultiple)
        {
            return i;
        }
    }
    return 0;
}
