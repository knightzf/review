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

using namespace std;

class Solution {
public:
    int minStickers(vector<string>& stickers, string target)
    {
        int n = stickers.size();

        std::vector<std::vector<int>> stickerHis(n, std::vector<int>(26, 0));
        for(int i = 0; i < n; ++i)
        {
            const std::string& sticker = stickers[i];
            for(char c: sticker)
            {
                stickerHis[i][c - 'a']++;
            }
        }

        std::unordered_map<std::string, int> dp; //min stickers for given string
        dp[""] = 0;

        return helper(stickerHis, dp, target);
    }

    int helper(const std::vector<std::vector<int>>& stickerHis,
               std::unordered_map<std::string, int>& dp,
               const std::string& target)
    {
        if(dp.find(target) != dp.end())
        {
            return dp[target];
        }

        std::vector<int> targetHis(26, 0);
        for(char c : target)
        {
            targetHis[c - 'a']++;
        }

        int ans = INT_MAX;

        for(int i = 0; i < stickerHis.size(); ++i)
        {
            std::string s;
            for(int j = 0; j < 26; ++j)
            {
                if(targetHis[j] - stickerHis[i][j] > 0)
                {
                    s += std::string(targetHis[j] - stickerHis[i][j], 'a' + j);
                }
            }

            if(s.size() != target.size())
            {
                int temp = helper(stickerHis, dp, s);
                if(temp != -1)
                {
                    ans = std::min(temp + 1, ans);
                }
            }
        }

        dp[target] = ans == INT_MAX ? -1 : ans;
        return dp[target];
    }
};

int main()
{
    Solution sol;
    vector<string> stickers{"with", "example", "science"};
    std::cout<<sol.minStickers(stickers, "thehat")<<std::endl;;
    return 0;
}
