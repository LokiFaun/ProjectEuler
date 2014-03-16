#include "ProjectEuler.h"
#include "Utility.h"

int Problem_4_Largest_Palindrome_Product()
{
    std::vector<int> palindromes;
    for (int i = 999; i > 99; i--)
    {
        for (int j = 999; j > 99; j--)
        {
            int value = i * j;
            std::string valueStr = to_string(value);
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
