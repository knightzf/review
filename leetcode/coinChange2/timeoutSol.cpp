#include "header.h"

class Solution {
private:
    int n;
    unordered_map<int, unordered_map<int, int>> m;
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        n = coins.size();
        m.clear();
        sort(coins.begin(), coins.end(), std::greater<int>());
        return impl(coins, 0, amount);
    }

    int impl(vector<int>& coins, int idx, int amount)
    {
        if(m.count(amount) && m[amount].count(idx)) return m[amount][idx];

        if(amount == 0) return 1;
        if(idx == n - 1) return amount % coins[idx] == 0;
        int res = 0;
        for(int i = idx; i < n; ++i)
        {
            if(coins[i] <= amount)
            {
                int j = 1;
                while(coins[i] * j <= amount)
                {
                    res += impl(coins, i + 1, amount - coins[i] * j);
                    ++j;
                }
            }
        }
        m[amount][idx] = res;
        return res;
    }
};

int main()
{
    Solution s;
}
