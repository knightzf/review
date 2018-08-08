#include "header.h"

class Solution {
    int mod = 1e9 + 7;
public:
    int findDerangement(int n) {
        if(n <= 2) return n - 1;
        int n1 = 0, n2 = 1;
        int res = 0;
        for(int i = 3; i <= n; ++i)
        {
            res = long(i - 1) * (n1 + n2) % mod;
            n1 = n2;
            n2 = res;
        }
        return res;
    }
};



int main() {
    Solution s;
    cout<<s.findDerangement(1000000)<<endl;

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
