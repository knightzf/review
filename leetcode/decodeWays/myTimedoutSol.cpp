#include "header.h"

class Solution {
public:
    int numDecodings(string s) {
        int cnt = 0;
        impl(s, 0, s.size(), cnt);
        return cnt;
    }

    void impl(const std::string& s, int idx, int n, int& cnt)
    {
        if(idx == n && n != 0)
        {
            ++cnt;
            return;
        }

        if(s[idx] != '0')
            impl(s, idx + 1, n, cnt);
        if(idx + 1 < n && isValid(s.substr(idx, 2)))
            impl(s, idx + 2, n, cnt);
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
    std::cout<<s.numDecodings("1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565")<<std::endl;
}
