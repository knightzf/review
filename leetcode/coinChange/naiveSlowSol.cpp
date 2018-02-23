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
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        std::sort(coins.begin(), coins.end());
        return impl(coins, amount, 0);
    }

    int impl(vector<int>& coins, int amount, int count)
    {
        std::cout<<"amount " <<amount<<" "<<count<<std::endl;
        int res = -1;
        //if(coins[0] > amount) return res;
        for(int i = coins.size() - 1; i >= 0; --i)
        {
            if(amount == coins[i]) return count + 1;
            else if(amount > coins[i])
            {
                //std::cout<<"here"<<std::endl;
                int r = impl(coins, amount - coins[i], count + 1);
                if(r != -1)
                {
                    if(res == -1) res = r;
                    else res = min(res, r);
                }
            }
            //else break;
        }

        return res;
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
