#include "ProjectEuler.h"
#include "Utility.h"

long Problem_3_LargestPrimeFactor()
{
    long long value = 600851475143;
    for (long i = static_cast<long>(sqrt(value)); i > 2; i--)
    {
        if (is_prime(i) && (value % i == 0))
        {
            return i;
        }
    }
    return 0;
}
