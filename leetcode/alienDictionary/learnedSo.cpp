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
    string alienOrder(vector<string>& words) {
        std::unordered_map<char, int> degree;
        for(const auto& w : words)
        {
            for(auto c: w)
                degree[c] = 0;
        }

        std::unordered_map<char, std::unordered_set<char>> m;
        for(int i = 0; i < words.size() - 1; ++i)
        {
            int maxLen = std::min(words[i].size(), words[i + 1].size());
            for(int j = 0; j < maxLen; ++j)
            {
                if(words[i][j] != words[i + 1][j])
                {
                    auto p = m[words[i][j]].insert(words[i + 1][j]);
                    if(p.second)
                    {
                        degree[words[i + 1][j]] += 1;
                    }
                    break;
                }
            }
        }

        std::unordered_set<char> free;

        for(auto iter = degree.begin(); iter != degree.end(); ++iter)
        {
            if(iter->second == 0)
            {
                free.insert(iter->first);
            }
        }

        std::string res;
        while(!free.empty())
        {
            char c = *free.begin();
            free.erase(c);

            if(m.find(c) != m.end())
            {
                const auto& s = m[c];
                for(auto d : s)
                {
                    --degree[d];
                    if(degree[d] == 0)
                    {
                        free.insert(d);
                    }
                }
            }

            res += c;
        }

        if(res.size() != degree.size()) return "";
        return res;
    }
};

int main() {
    Solution s;
    //vector<string> a{"wrt","wrf","er","ett","rftt"};
    //vector<string> a{"wrt","wrtkj"};
    vector<string> a{"za","zb", "ca", "cb"};
    std::cout<<s.alienOrder(a)<<std::endl;
}
