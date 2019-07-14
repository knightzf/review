#include "header.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> m;
        for(int i = 1; i <= amount; ++i) m[i] = INT_MAX;
        for(int c : coins) m[c] = 1;
        for(int i = 1; i <= amount; ++i) {
            if(m[i] == INT_MAX) {
                for(int c : coins) {
                    if(i > c && m[i - c] != INT_MAX)
                        m[i] = min(m[i], 1 + m[i - c]);
                }
            }
        }
        return m[amount] == INT_MAX ? -1 : m[amount];
    }
};

int main()
{
    Solution s;
}