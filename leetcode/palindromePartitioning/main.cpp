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
    bool isPalindrome(const std::string& s)
    {
        if(s.size() < 1) return true;

        if(palinMap.find(s) != palinMap.end())
        {
            return palinMap[s];
        }

        int i = 0;
        int j = s.size() - 1;

        bool isPalin = true;

        while(i < j)
        {
            if(s[i] != s[j])
            {
                isPalin = false;
                break;
            }
            ++i;
            --j;
        }

        palinMap[s] = isPalin;

        return isPalin;
    }

    vector<vector<string>> partition(string s)
    {
        if(palinCache.find(s) != palinCache.end())
        {
            return palinCache[s];
        }

        vector<vector<string>> res;
        if(s.size() == 1)
        {
            res.push_back({s});
            return res;
        }

        for(int i = 0; i < s.size(); ++i)
        {
            std::string pre = s.substr(0, i + 1);
            if(isPalindrome(pre))
            {
                if(i == s.size() - 1)
                {
                    res.push_back({pre});
                }
                else
                {
                    const auto& r = partition(s.substr(i + 1));
                    for(const auto& v : r)
                    {
                        std::vector<string> t{pre};
                        t.insert(t.end(), v.begin(), v.end());
                        res.emplace_back(t);
                    }
                }
            }
        }

        palinCache[s] = res;

        return res;
    }

private:
    std::unordered_map<std::string, bool> palinMap;
    std::unordered_map<std::string, vector<vector<string>>> palinCache;
};

int main()
{
    Solution s;
    const auto& r = s.partition("bb");
    for(auto i : r)
    {
        for(auto j : i)
        {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
}
