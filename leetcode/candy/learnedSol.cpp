#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
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

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings)
    {
        int n = ratings.size();

        if(n < 2)
        {
            return n;
        }

        std::vector<int> candies(n, 1);

        for(int i = 1; i < n; ++i)
        {
            if(ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for(int i = n - 2; i >= 0; --i)
        {
            if(ratings[i] > ratings[i + 1])
            {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }

        for(auto c : candies)
            {
                std::cout<<c<<" ";
            }
            std::cout<<std::endl;

        int sum = 0;
        for(auto c : candies)
        {
            sum += c;
        }

        return sum;
    }
    /*int candy(vector<int>& ratings)
    {
        int n = ratings.size();

        if(n < 2)
        {
            return n;
        }

        std::vector<int> dp(n + 1, 0);
        dp[1] = 1;

        for(int i = 1; i < ratings.size(); ++i)
        {
            if(ratings[i] < ratings[i - 1])
            {
                if(dp[i] - dp[i - 1] == 1)
                {
                    int diff = 1;
                    int j = i;
                    while(dp[j] - dp[j - 1] == diff && j > 0)
                    {
                        --j;
                        ++diff;
                    }
                    //++j;

                    std::cout<<"j "<<j<<" i "<<i<<std::endl;
                    for(int k = j; k < i; ++k)
                    {
                        dp[k] += k - j + 1;
                    }
                }
                dp[i + 1] = dp[i] + 1;
            }
            else if(ratings[i] == ratings[i - 1])
            {
                dp[i + 1] = dp[i] + 1;
            }
            else
            {
                dp[i + 1] = dp[i] + dp[i] - dp[i - 1] + 1;
            }

            for(auto x : dp)
            {
                std::cout<<x<<" ";
            }
            std::cout<<std::endl;
        }

        return dp[n];
    }*/
};

int main()
{
    Solution s;
    //vector<int> a{1, 3, 4, 3, 2, 1};
    //vector<int> a{4, 3, 2, 1};
    //vector<int> a{3, 3, 2};
    vector<int> a{1, 0, 2};
    s.candy(a);
}
