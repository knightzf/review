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

using namespace std;

class Solution {
public:
    bool isValid(const std::string& s)
    {
        int count = 0;
        for(size_t i = 0, sz = s.size(); i < sz; ++i)
        {
            if(s[i] == '(')
            {
                ++count;
            }
            else
            {
                --count;
            }

            if(count < 0)
                return false;
        }

        return true;
    }

    int countSetBits(unsigned int num)
    {
        unsigned int count = 0;
        while (num)
        {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

    vector<string> generateParenthesis(int n)
    {
        std::vector<string> result;

        if(!n)
        {
            return result;
        }

        std::string s(n * 2, ')');
        s[0] = '(';
        size_t totalDigits = n * 2;

        for(size_t i = 0, sz = std::pow(2, (n -1) * 2); i < sz; ++i)
        {
            //std::cout<<i<<" "<<countSetBits(i)<<std::endl;

            if(countSetBits(i) == n - 1)
            {
                std::string tempS = s;
                size_t tempI = i;
                int count = 0;
                while(tempI)
                {
                    if(tempI & 1)
                    {
                        tempS[totalDigits - 2 - count] = '(';
                    }

                    tempI >>= 1;
                    ++count;
                }

                //std::cout<<"tempS "<<tempS<<" "<<i<<std::endl;

                if(isValid(tempS))
                {
                    result.push_back(tempS);
                }
            }
        }

        return result;

    }
};

int main()
{
    Solution sol;
    const auto & a = sol.generateParenthesis(3);
    for(const auto& i : a)
    {
        std::cout<<i<<std::endl;
    }
    return 0;
}
