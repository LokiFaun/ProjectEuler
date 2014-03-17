#include "ProjectEuler.h"
#include <cmath>

long long Problem_9_SpecialPythagoreanTriplet()
{
    long long s = 1000;
    for (long long a = 1; a < s / 3; a++)
    {
        for (long long b = 1; b < s / 2; b++)
        {
            const long long c = s - a - b;
            if (pow(a, 2) + pow(b, 2) == pow(c, 2))
            {
                return a * b * c;
            }
        }
    }
    return 0;
}

