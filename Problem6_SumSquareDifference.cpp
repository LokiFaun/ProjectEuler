#include "ProjectEuler.h"
#include "Utility.h"

int Problem_6_SumQuareDifference()
{
    std::vector<int> numbers = generate_range(1, 100);
    const int sum = std::accumulate(std::begin(numbers), std::end(numbers), 0);
    const int sumSquared = static_cast<int>(std::pow(sum, 2));
    std::transform(std::begin(numbers), std::end(numbers), std::begin(numbers), std::bind((double(*)(int, int))std::pow, std::placeholders::_1, 2));
    const int sumSquaredNumbers = std::accumulate(std::begin(numbers), std::end(numbers), 0);
    return std::max(sumSquared, sumSquaredNumbers) - std::min(sumSquared, sumSquaredNumbers);
}
