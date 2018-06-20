#include "header.h"

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<int> m(amount + 1, 0);
        m[0] = 1;
        for(int i = 0; i < n; ++i)
        {
            for(int k = 0; k <= amount; ++k)
            {
                if(m[k] > 0)
                {
                    if(k + coins[i] <= amount)
                        m[k + coins[i]] += m[k];
                }
            }
        }

        return m[amount];
    }
};

int main()
{
    Solution s;
    {
        vector<int> a{102, 89, 76, 63, 50, 37, 24, 11};
        cout<<s.change(5000, a)<<endl;
    }
    {
        vector<int> a{1, 2, 5};
        cout<<s.change(5, a)<<endl;
    }
}
