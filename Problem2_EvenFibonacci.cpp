#include "ProjectEuler.h"
#include "Utility.h"
#include <vector>
#include <algorithm>

int Problem_2_EvenFibonacci()
{
    const int maxValue = 4000000;
    int sum = 0;
    std::vector<int> numbers;
    numbers.push_back(0);
    numbers.push_back(1);
    for (int i = 1;; i++)
    {
        int value = numbers[i - 1] + numbers[i];
        if (value > maxValue)
        {
            break;
        }
        numbers.push_back(value);
        if (value % 2 == 0)
        {
            sum += value;
        }
    }
    return sum;
}

