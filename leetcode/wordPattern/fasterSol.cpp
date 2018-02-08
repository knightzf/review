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
        std::unordered_map<string, char> m;
        std::vector<bool> vb(26, false);
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

        for(int i = 0; i < v.size(); ++i)
        {
            if(m.find(v[i]) == m.end())
            {
                if(vb[pattern[i] - 'a'] == true) return false;

                m[v[i]] = pattern[i];
                vb[pattern[i] - 'a'] = true;
            }
            else
            {
                if(m[v[i]] != pattern[i]) return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    s.wordPattern("abba", "dog cat cat dog");
}
