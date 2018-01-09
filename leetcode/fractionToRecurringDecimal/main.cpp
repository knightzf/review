#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int sign = ((long)numerator * (long)denominator) >= 0;
        long N = std::abs((long)numerator);
        long D = std::abs((long)denominator);

        std::string integer, decimal;
        integer = (sign ? "" : "-") + std::to_string(N / D);

        long res = N % D;
        if(res != 0)
        {
            std::unordered_map<int, int> resSet;
            int idx = 0;
            resSet[res] = idx;
            while(res)
            {
                res *= 10;

                long tempDecimal = res / D;
                res = res % D;

                decimal += std::to_string(tempDecimal);

                if(resSet.find(res) != resSet.end())
                {
                    decimal.insert(resSet[res], "(");
                    decimal.push_back(')');
                    break;
                }
                else
                {
                    ++idx;
                    resSet[res] = idx;
                }


            }

            integer += "." + decimal;
        }

        return integer;
    }
};
int main()
{
    Solution s;
    std::cout<<s.fractionToDecimal(2, 3)<<std::endl;
    std::cout<<s.fractionToDecimal(123, 13)<<std::endl;
    std::cout<<s.fractionToDecimal(4, 2)<<std::endl;
    std::cout<<s.fractionToDecimal(1, 90)<<std::endl;
    std::cout<<s.fractionToDecimal(-50, 8)<<std::endl;
    std::cout<<s.fractionToDecimal(-1, -2147483648)<<std::endl;
}
