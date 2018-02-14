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
        int n = s.size();
        vector<string> res;
        impl(s, 0, 0, n, true, res);
        return res;
    }

    void impl(const std::string& s, int startIdx, int startRemoveIdx, int endIdx, bool fromLeft, vector<string>& res)
    {
        char left, right;
        if(fromLeft)
        {
            left = '(';
            right = ')';
        }
        else
        {
            left = ')';
            right = '(';
        }

        int cnt = 0;
        for(int i = startIdx; i < endIdx; ++i)
        {
            if(s[i] == left) ++cnt;
            else if(s[i] == right) --cnt;

            if(cnt < 0)
            {
                for(int j = startRemoveIdx; j <= i; ++j)
                {
                    if(s[j] == right && (j == startRemoveIdx || s[j - 1] != right))
                    {
                        //std::cout<<s.substr(0, j) + s.substr(j + 1, endIdx - j - 1)<<std::endl;
                        impl(s.substr(0, j) + s.substr(j + 1, endIdx - j - 1),
                             i, j, endIdx - 1, fromLeft, res);
                    }
                }
                return;
            }
        }

        string t = s;
        std::reverse(t.begin(), t.end());
        if(fromLeft)
        {
            impl(t, 0, 0, endIdx, !fromLeft, res);
        }
        else
        {
            res.push_back(t);
        }
    }

};

int main() {
    Solution s;
    //const auto& r = s.removeInvalidParentheses("()())()");
    const auto& r = s.removeInvalidParentheses("(r(()()(");
    for(auto i : r)
    {
        std::cout<<i<<std::endl;
    }
}
