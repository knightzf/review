#include "header.h"

class Solution {
public:
    bool queryString(string S, int N) {
        int n = S.size();
        if(n * n < N) return false;
        for(int i = 1; i <= N; ++i)
        {
            if(S.find(convert(i)) == string::npos) return false;
        }
        return true;
    }

    std::string convert(int i)
    {
        std::string res;
        while(i)
        {
            int mod = i % 2;
            i /= 2;
            res += mod ? "1" : "0";
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.convert(6)<<endl;
}
