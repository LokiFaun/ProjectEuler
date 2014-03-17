#include "ProjectEuler.h"
#include "Utility.h"

long long Problem_4_Largest_Palindrome_Product()
{
    std::vector<long long> palindromes;
    for (int i = 999; i > 99; i--)
    {
        for (int j = 999; j > 99; j--)
        {
            long long value = i * j;
            std::string valueStr = std::to_string(value);
            std::string reverseStr = valueStr;
            std::reverse(std::begin(reverseStr), std::end(reverseStr));
            if (valueStr.compare(reverseStr) == 0)
            {
                palindromes.push_back(value);
            }
        }
    }
    return *std::max_element(std::begin(palindromes), std::end(palindromes));
}
