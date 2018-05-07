#include "header.h"

class Solution {
public:
    string maskPII(string S) {
        int n = S.size();
        if(S.find('@') != string::npos)
        {
            int i = S.find('@');
            const auto& name = S.substr(0, i);
            for(int j = i + 1; j < n; ++j)
            {
                S[j] = std::tolower(S[j]);
            }
            return string(1, std::tolower(name.front())) + "*****" +
                string(1, std::tolower(name.back())) + S.substr(i);
        }
        else
        {
            string number;
            for(int i = 0; i < n; ++i)
            {
                if(std::isdigit(S[i]))
                {
                    number += S[i];
                }
            }

            string res;
            if(number.size() > 10)
            {
                res += "+" + string(number.size() - 10, '*') + "-";
            }
            string locaCode = number.substr(number.size() - 4);
            return res + "***-***-" + locaCode;
        }
    }
};

int main()
{
    Solution s;
    std::cout<<s.maskPII("LeetCode@LeetCode.com")<<std::endl;
    std::cout<<s.maskPII("AB@qq.com")<<std::endl;
    std::cout<<s.maskPII("1(234)567-890")<<std::endl;
    std::cout<<s.maskPII("86-(10)12345678")<<std::endl;
}
