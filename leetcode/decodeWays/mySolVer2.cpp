#include "header.h"

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int n = s.size();
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        for(int i = 0; i < n; ++i)
        {
            if(s[i] != '0')
                dp1[i] = i > 0 ? (dp1[i - 1] + dp2[i - 1]) : 1;

            if(i > 0 && isValid(s.substr(i - 1, 2)))
            {
                dp2[i] = i > 1 ? (dp1[i - 2] + dp2[i - 2]) : 1;
            }
        }

        return dp1.back() + dp2.back();
    }

    bool isValid(const std::string& s)
    {
        if(s[0] != '1' && s[0] != '2') return false;
        int t = (s[0] - '0') * 10 + s[1] - '0';
        if(t >= 10 && t <= 26) return true;
        return false;
    }
};

int main()
{
    Solution s;
    std::cout<<s.numDecodings("")<<std::endl;
    std::cout<<s.numDecodings("0")<<std::endl;
    std::cout<<s.numDecodings("12")<<std::endl;
    std::cout<<s.numDecodings("27")<<std::endl;
    std::cout<<s.numDecodings("10")<<std::endl;
    std::cout<<s.numDecodings("110")<<std::endl;
    std::cout<<s.numDecodings("227")<<std::endl;
    std::cout<<s.numDecodings("12120")<<std::endl;
    std::cout<<s.numDecodings("1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565")<<std::endl;
}
