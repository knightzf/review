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
    bool wordPattern(string pattern, string str) {
        std::unordered_map<char, string> m;
        std::unordered_set<string> s;

        std::vector<string> v;
        int startIdx = 0;
        for(int i = 0; i < str.size(); ++i)
        {
            if(str[i] == ' ')
            {
                v.push_back(str.substr(startIdx, i - startIdx));
                startIdx = i + 1;
            }
            else if(i == str.size() - 1)
            {
                v.push_back(str.substr(startIdx, i - startIdx + 1));
                startIdx = i + 1;
            }
        }

        if(v.size() != pattern.size()) return false;

        for(int i = 0; i < pattern.size(); ++i)
        {
            char c = pattern[i];
            if(m.find(c) == m.end())
            {
                if(s.find(v[i]) == s.end())
                {
                    m[c] = v[i];
                    s.insert(v[i]);
                }
                else return false;
            }
            else
            {
                if(v[i] != m[c]) return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    s.wordPattern("abba", "dog cat cat dog");
}
