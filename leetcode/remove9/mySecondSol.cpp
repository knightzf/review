#include "header.h"

class Solution {
public:
    int newInteger(int n) {
        static vector<long> m;
        static vector<long> v;
        if(m.empty())
        {
            long sum = 0;
            long sum1 = 0;
            for(int i = 0; i < 10; ++i)
            {
                if(i == 0) {
                    m.push_back(1);
                }
                else
                {
                    m.push_back(sum * 8 + pow(10, i));
                }

                sum += m.back();
                v.push_back(pow(10, i + 1) - sum);
            }
        }

        /*for(int i : m)
            cout<<i<<endl;

        for(long i : v)
            cout<<i<<endl;
        //*/
        for(int i = 0; i < 10; ++i)
        {
            if(v[i] == n)
                return pow(10, i + 1);
            else if(v[i] > n)
            {
                long res = 0;
                int j = i - 1;
                while(j >= 0)
                {
                    res += (n / v[j]) * pow(10, j + 1);
                    n = n % v[j];
                    while(v[j] > n)
                    {
                        --j;
                    }
                }
                return res + n;
            }
        }
    }
};

int main() {
    Solution s;
    cout<<s.newInteger(81)<<endl;
    cout<<s.newInteger(56)<<endl;
    cout<<s.newInteger(500)<<endl;
    cout<<s.newInteger(800000000)<<endl;
}
