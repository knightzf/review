#include "header.h"

class Solution {
public:
    string baseNeg2(int N) {
        string res;
        int div = 2;
        while(N)
        {
            if(N % 2 == 0) res += '0';
            else
            {
                if(div < 0) N += 2;
                res += '1';
            }
            
            N /= 2;
            div = -div;
        }
        reverse(res.begin(), res.end());
        if(res.empty()) res = "0";
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.baseNeg2(2)<<endl;
    cout<<s.baseNeg2(3)<<endl;
    cout<<s.baseNeg2(4)<<endl;
    cout<<s.baseNeg2(8)<<endl;
    cout<<s.baseNeg2(9)<<endl;
}
