#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

class Solution {
private:
    int total = INT_MAX;
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0 || coins.empty()) return 0;
        std::sort(coins.begin(), coins.end());
        impl(coins, amount, coins.size() - 1, 0);
        return total == INT_MAX ? -1 : total;
    }

    void impl(vector<int>& coins, int amount, int idx, int count)
    {
        while(idx >= 0 && coins[idx] > amount) --idx;
        if(idx < 0) return;

        int cnt = amount / coins[idx];
        if(amount % coins[idx] == 0)
        {
            if(count + cnt < total)
            {
                total = count + cnt;
            }
            return;
        }

        for(int i = cnt; i >= 0; --i)
        {
            int rem = amount - coins[idx] * i;
            int newCount = count + i;
            if(rem > 0 &&  newCount < total)
                impl(coins, amount - coins[idx] * i, idx - 1, newCount);
            else if (newCount >= total-1)
                break;
        }
    }
};

int main() {
    Solution s;
    //vector<int> a{1, 2, 5};
    //std::cout<<s.coinChange(a, 11)<<std::endl;
    //vector<int> a{2};
    //std::cout<<s.coinChange(a, 3)<<std::endl;
    vector<int> a{186, 419, 83, 408};
    std::cout<<s.coinChange(a, 6249)<<std::endl;
}
