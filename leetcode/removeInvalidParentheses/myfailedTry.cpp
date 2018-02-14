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
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int n = s.size();

        vector<std::pair<int, int>> v;
        int c = 0;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '(')
            {
                ++c;
            }
            if(s[i] == ')')
            {
                --c;
            }

            if(c < 0)
            {
                v.emplace_back(i, c);
                c = 0;
            }
        }

        if(c > 0)
        {
            v.emplace_back(n - 1, c);
        }

        if(v.empty()) return res;

        return impl(s, v, 0);
    }

    vector<string> impl(const std::string& s, vector<std::pair<int, int>>& v, int idx)
    {
        vector<string> res;

        if(idx == v.size()) return res;

        int startIdx = 0;
        if(idx != 0) startIdx = v[idx - 1].first + 1;
        int endIdx = v[idx].first;

        std::unordered_set<string> st;
        if(v[idx].second < 0)
        {
            for(int i = startIdx; i <= endIdx; ++i)
            {
                if(s[i] == ')')
                {
                    std::string t = s.substr(startIdx, i - startIdx) + s.substr(i + 1, endIdx - i);
                    if(st.find(t) == st.end())
                    {
                        st.insert(t);
                        const auto& r = impl(s, v, idx + 1);
                        for(const auto& x : r) res.push_back(t + x);
                    }
                }
            }
        }
        else
        {
            const auto& r = test(s.substr(startIdx, endIdx - startIdx + 1), v[idx].second);
        }

        return res;
    }

    vector<string> test(const std::string& s, int cnt)
    {
        vector<string> res;
        std::unordered_set<string> st;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] = '(')
            {
                std::string t = s.substr(startIdx, i - startIdx) + s.substr(i + 1, endIdx - i);
            }
        }
    }

private:
    bool isValid(const std::string& s/*, int startIdx, int endIdx*/)
    {
        int n = s.size();
        int c = 0;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '(')
            {
                ++c;
            }
            if(s[i] == ')')
            {
                --c;
            }

            if(c < 0)
            {
                return false;
            }
        }

        return c == 0;
    }
};

int main() {
    Solution s;
}
