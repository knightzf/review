#include "header.h"

class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);
        for(int m = 60; m > 0; --m)
        {
            long long kLow = 2;
            long long kHigh = static_cast<long long>(pow(num, 1.0 / m));
            if(m == 1) kHigh = num;
            //cout<<m<<" "<<kLow<<" "<<kHigh<<endl;

            while(kLow <= kHigh)
            {
                long long kMid = (kLow + kHigh) / 2;
                long long t = 0;
                long long res = 0;
                for(int i = 0; i < m + 1; ++i)
                {
                    t = t * kMid + 1;
                }
                if(t == num) return to_string(kMid);
                if(t > num) kHigh = kMid - 1;
                else kLow = kMid + 1;
            }
        }
        return "";
    }
};

int main()
{
    Solution s;
    cout<<s.smallestGoodBase("727004545306745403")<<endl;
}
