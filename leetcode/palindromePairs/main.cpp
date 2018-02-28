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
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        int n = words.size();
        if(n < 2) return res;

        std::unordered_map<std::string, int> m;
        for(int i = 0; i < n; ++i)
        {
            m[words[i]] = i;
        }

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j <= words[i].size(); ++j)
            {
                const string& s1 = words[i].substr(0, j);
                const string& s2 = words[i].substr(j);

                if(isPalindrome(s1))
                {
                    string t = s2;
                    std::reverse(t.begin(), t.end());
                    if(m.find(t) != m.end() && m[t] != i)
                    {
                        res.push_back({m[t], i});
                    }
                }

                if(!s2.empty() && isPalindrome(s2))
                {
                    string t = s1;
                    std::reverse(t.begin(), t.end());
                    if(m.find(t) != m.end() && m[t] != i)
                    {
                        res.push_back({i, m[t]});
                    }
                }
            }
        }
        return res;
    }
private:
    bool isPalindrome(const std::string& s)
    {
        int i = 0, j = s.size() - 1;
        while(i < j)
        {
            if(s[i++] != s[j--]) return false;
        }

        return true;
    }
};


int main() {
    Solution s;
}
