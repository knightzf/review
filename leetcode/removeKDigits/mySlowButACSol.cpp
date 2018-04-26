#include "header.h"

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == n) return "0";
        string res;
        impl(num, res, n - k);
        int i = 0;
        while(res[i] == '0') ++i;
        return i == res.size() ? "0" : res.substr(i);
    }

    void impl(string& num, string& res, int cnt)
    {
        if(cnt == 0) return;

        int i = num.size() - cnt;
        char minDigit = num[i];
        int minIdx = i;
        for(; i >= 0; --i)
        {
            if(num[i] <= minDigit)
            {
                minDigit = num[i];
                minIdx = i;
            }
        }

        res += minDigit;
        num = num.substr(minIdx + 1);
        //std::cout<<num<<" "<<res<<std::endl;
        impl(num, res, cnt - 1);
    }
};

int main()
{
    Solution s;
    std::cout<<s.removeKdigits("10", 1)<<std::endl;
}
