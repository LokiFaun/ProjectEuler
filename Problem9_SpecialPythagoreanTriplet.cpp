#include "ProjectEuler.h"
#include <cmath>

int Problem_9_SpecialPythagoreanTriplet()
{
    int s = 1000;
    for (int a = 1; a < s / 3; a++)
    {
        for (int b = 1; b < s / 2; b++)
        {
            const int c = s - a - b;
            if (pow(a, 2) + pow(b, 2) == pow(c, 2))
            {
                return a * b * c;
            }
        }
    }
    return 0;
}

