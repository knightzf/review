#include "header.h"

class Solution {
public:
    int maxA(int N) {
        static unordered_map<int, int> m;
        if(N <= 5) return N;
        if(!m.count(N))
        {
            int res = 0;
            for(int i = 1; i <= N - 3; ++i)
            {
                int t = maxA(i);
                //cout<<i<<" "<<res<<endl;
                int n = N - i;
                while(n >= 3)
                {
                    t *= 2;
                    n -= 3;
                }

                t += t / 2 * n;
                res = max(res, t);
            }

            m[N] = res;
        }
        return m[N];
    }
};

int main() {
    Solution s;
    cout<<s.maxA(50)<<endl;
}
