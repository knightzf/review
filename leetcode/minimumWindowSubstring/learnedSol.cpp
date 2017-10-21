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
    string minWindow(string s, string t)
    {
        if(t.empty())
        {
            return "";
        }

        std::vector<int> map(128, 0);

        for(char c : t)
        {
            map[c]++;
        }

        int minLen = INT_MAX;
        int minStartIdx = 0;
        int unmatchedCount = t.size();

        int startIdx = 0;
        int endIdx = 0;

        while(endIdx != s.size())
        {
            if(map[s[endIdx]] > 0)
            {
                --unmatchedCount;
            }

            map[s[endIdx]]--;
            ++endIdx;

            while(unmatchedCount == 0)
            {
                int len = endIdx - startIdx;
                if(len < minLen)
                {
                    minLen = len;
                    minStartIdx = startIdx;
                }

                map[s[startIdx]]++;
                if(map[s[startIdx]] > 0)
                {
                    ++unmatchedCount;
                }
                ++startIdx;
            }
        }

        if(minLen != INT_MAX)
        {
            return s.substr(minStartIdx, minLen);
        }

        return "";
    }
};

int main()
{
    Solution sol;
    return 0;
}
