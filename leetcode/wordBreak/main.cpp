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
};

int main()
{
    Solution s;
    vector<string> a{"leet", "code"};
    std::cout<<s.wordBreak("leetcode", a)<<std::endl;
}
