#include "ProjectEuler.h"
#include "Utility.h"
#include <vector>
#include <algorithm>

bool IsMultiple(int i)
{
    return (i % 3 == 0) || (i % 5 == 0);
}

long long Problem_1_Multiples_3_5()
{
    std::vector<long long> range = generate_range(0LL, 1000LL);
    std::vector<long long> numbers;
    auto isMultiple = [&numbers] (int i)
    {
      if (IsMultiple(i))
      {
          numbers.push_back(i);
      }
    };
    std::for_each(std::begin(range), std::end(range), isMultiple);
    return std::accumulate(std::begin(numbers), std::end(numbers), 0);
}
