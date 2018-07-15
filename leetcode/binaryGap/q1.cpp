#include "header.h"

class Solution {
public:
    int binaryGap(int N) {
        int res = 0;
        int prev = -1;
        int idx = 0;
        while(N)
        {
            int t = N % 2;
            if(t == 1)
            {
                if(prev != -1)
                {
                    res = max(res, idx - prev);
                }
                prev = idx;
            }
            N = N >> 1;
            ++idx;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.binaryGap(22)<<endl;
    cout<<s.binaryGap(5)<<endl;
    cout<<s.binaryGap(6)<<endl;

}
