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
        if(pattern.empty()) return false;

        std::unordered_map<string, char> m;
        std::vector<bool> vb(26, false);

        int patternIdx = 0;
        int startIdx = 0;
        for(int i = 0; i < str.size(); ++i)
        {
            if(str[i] == ' ' || i == str.size() - 1)
            {
                string s;
                if(str[i] == ' ')
                {
                    s = str.substr(startIdx, i - startIdx);
                    startIdx = i + 1;
                }
                else
                {
                    s = str.substr(startIdx, i - startIdx + 1);
                }

                if(m.find(s) == m.end())
                {
                    if(vb[pattern[patternIdx] - 'a'] == true) return false;

                    m[s] = pattern[patternIdx];
                    vb[pattern[patternIdx] - 'a'] = true;
                }
                else
                {
                    if(m[s] != pattern[patternIdx]) return false;
                }

                ++patternIdx;
            }
        }

        if(patternIdx != pattern.size()) return false;

        return true;
    }
};

int main() {
    Solution s;
    s.wordPattern("abba", "dog cat cat dog");
}
