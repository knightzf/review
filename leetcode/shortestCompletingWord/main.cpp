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
    string shortestCompletingWord(string licensePlate, vector<string>& words)
    {
        std::vector<int> m(26, 0);
        for(char c : licensePlate)
        {
            if(std::isalpha(c))
            {
                ++m[tolower(c) - 'a'];
            }
        }

        std::vector<std::pair<int, int>> vp;
        for(int i = 0; i < 26; ++i)
        {
            if(m[i])
            {
                vp.push_back(std::make_pair(i, m[i]));
            }
        }

        std::string res;
        int minLen = INT_MAX;

        for(const auto& w : words)
        {
            std::vector<int> v(26, 0);
            for(char c : w)
            {
                ++v[c - 'a'];
            }

            bool match = true;
            for(const auto& item : vp)
            {
                if(v[item.first] < item.second)
                {
                    match = false;
                    break;
                }
            }

            if(match)
            {
                if(w.size() < minLen)
                {
                    minLen = w.size();
                    res = w;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    std::string a = "1s3 456";
    std::vector<std::string> w{"looks", "pest", "stew", "show"};
    std::cout<<s.shortestCompletingWord(a,w)<<std::endl;
}
