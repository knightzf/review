#include "header.h"

class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.size() + 1;
        int num = 1;

        vector<int> res(n, 0);
        for(int i = 0; i < n - 1; )
        {
            if(s[i] == 'I')
            {
                res[i] = num++;
                ++i;
            }
            else
            {
                int j = i;
                while(j < n - 1 && s[j] == 'D') ++j;
                for(int k = j; k >= i; --k)
                {
                    res[k] = num++;
                }
                i = j + 1;
            }
        }
        if(res.back() == 0) res.back() = num;
        return res;
    }
};

int main()
{
    Solution s;
    const auto& r = s.findPermutation("I");
    for(int i : r)
        cout<<i<<" ";
    cout<<endl;
}
