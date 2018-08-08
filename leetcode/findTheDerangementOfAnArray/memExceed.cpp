#include "header.h"

class Solution {
    unordered_map<int, unordered_map<int, int>> m;
    int mod = 1e9 + 7;
public:
    int findDerangement(int n) {
        return impl(n, n);
    }

    int impl(int total, int inrange)
    {
        if(m.count(total) && m[total].count(inrange)) return m[total][inrange];
        int res = 0;
        if(inrange == 0)
        {
            res = factorial(total);
        }
        else if(total == inrange) {
            if(total == 1) res = 0;
            else if(total == 2) res = 1;
            else res = long(total - 1) * impl(total - 1, inrange - 2) % mod;
        }
        else {
            res = (long(total - inrange) * impl(total - 1, inrange) % mod +
                   long(inrange) * impl(total - 1, inrange - 1) % mod) % mod;
        }
        m[total][inrange] = res;
        return res;
    }

    int factorial(int n)
    {
        return (n == 1 || n == 0) ? 1 : factorial(n - 1) * long(n) % mod;
    }
};


int main() {
    Solution s;
    cout<<s.findDerangement(5)<<endl;

    /*int n = 5;
    vector<int> v;
    for(int i = 1; i <= n; ++i)
    {
        v.push_back(i);
    }

    int cnt = 0;
    do {
        bool good = true;
        for(int i = 0; i < n; ++i)
        {
            if(v[i] == i + 1)
            {
                good = false;
                break;
            }
        }
        if(good)
        {
            for(int i = 0; i < n; ++i)
                cout<<v[i]<<" ";
            cout<<endl;
            ++cnt;
        }

    } while(next_permutation(v.begin(), v.end()));

    cout<<n<<" "<<cnt<<endl;*/
}
