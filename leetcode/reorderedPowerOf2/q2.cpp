#include "header.h"

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        static unordered_map<int, vector<vector<int>>> m;
        if(m.empty())
        {
            for(int i = 0; i < 100; ++i)
            {
                int t = pow(2, i);
                if(t > 1000000000) break;

                int digits = (int)log10(t) + 1;
                vector<int> v(10, 0);
                while(t)
                {
                    ++v[t % 10];
                    t /= 10;
                }
                m[digits].emplace_back(v);
            }
        }

        int digits = log10(N) + 1;
        vector<int> v(10, 0);
        while(N)
        {
            ++v[N % 10];
            N /= 10;
        }

        if(m.count(digits) == 0) return false;
        for(const auto& p : m[digits])
        {
            if(p == v) return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout<<s.reorderedPowerOf2(1)<<endl;
    cout<<s.reorderedPowerOf2(10)<<endl;
    cout<<s.reorderedPowerOf2(16)<<endl;
    cout<<s.reorderedPowerOf2(24)<<endl;
    cout<<s.reorderedPowerOf2(46)<<endl;
}
