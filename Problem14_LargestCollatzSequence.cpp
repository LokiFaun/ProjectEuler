#include "ProjectEuler.h"
#include "Utility.h"

std::vector<long long> CollatzSequence(long long number)
{
    std::vector<long long> sequence;
    sequence.push_back(number);
    while (sequence.back() > 1)
    {
        if (sequence.back() % 2 == 0)
        {
            sequence.push_back(sequence.back() / 2);
        }
        else
        {
            sequence.push_back(3 * sequence.back() + 1);
        }
    }
    return sequence;
}

long long Problem_14_LargestCollatzSequence()
{
    const long long start = 1000000;
    long long number = 0;
    long long size = 0;
    for (long long i = start; i > 0; i--)
    {
        long long sequence = i;
        long long length = 0;
        while (sequence != 1)
        {
            if (sequence % 2 == 0)
            {
                sequence = sequence / 2;
            }
            else
            {
                sequence = 3 * sequence + 1;
            }
            length++;
        }
        if (length > size)
        {
            size = length;
            number = i;
        }
    }
    return number;
}
