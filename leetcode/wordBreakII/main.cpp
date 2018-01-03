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
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
        std::unordered_map<std::string, vector<string>> cache;
        return impl(s, wordSet, cache);
    }

    vector<string> impl(const std::string& s,
                        std::unordered_set<std::string>& wordSet,
                        std::unordered_map<std::string, vector<string>>& cache)
    {
        if(cache.find(s) != cache.end())
        {
            return cache[s];
        }

        vector<string> res;

        if(wordSet.find(s) != wordSet.end())
        {
            res.push_back(s);
        }

        for(int i = 1; i < s.size(); ++i)
        {
            const auto& pre = s.substr(0, i);
            if(wordSet.find(pre) != wordSet.end())
            {
                const auto& r = impl(s.substr(i), wordSet, cache);
                if(!r.empty())
                {
                    for(const auto& sen : r)
                    {
                        res.push_back(pre + " " + sen);
                    }
                }
            }
        }

        if(cache.find(s) == cache.end())
        {
            cache[s] = res;
        }

        return res;
    }
};

/*class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());

        return impl(s, wordSet);
    }

    bool impl(const std::string& s, std::unordered_set<std::string>& wordSet)
    {
        if(wordSet.find(s) != wordSet.end()) return true;

        for(int i = 1; i < s.size(); ++i)
        {
            const auto& pre = s.substr(0, i);
            if(wordSet.find(pre) != wordSet.end())
            {
                int j = i;
                while(j + pre.size() <= s.size() && s.substr(j, pre.size()) == pre)
                {
                    j += pre.size();
                }

                if (j == s.size()) return true;
                if(impl(s.substr(j), wordSet)) return true;
            }
        }

        return false;
    }
};*/

int main()
{
    Solution s;
    vector<string> a{"aaaa", "aa", "a"};
    const auto& r = s.wordBreak("aaaaaaa", a);
    for(auto i : r)
    {
        std::cout<<i<<std::endl;
    }
}
