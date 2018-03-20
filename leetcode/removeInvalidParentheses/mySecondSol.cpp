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
#include <iterator>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        impl(s, 0, 0, res, true);
        return res;
    }

    void impl(const std::string& s, int startIdx, int lastRemoveIdx, vector<string>& res, bool fromLeft)
    {
        char leftC = fromLeft ? '(' : ')';
        char rightC = fromLeft ? ')' : '(';

        int cnt = 0;
        for(int i = startIdx; i < s.size(); ++i)
        {
            if(s[i] == leftC)
                ++cnt;
            else if(s[i] == rightC)
                --cnt;

            if(cnt < 0)
            {
                for(int j = lastRemoveIdx; j <= i; ++j)
                {
                    if(s[j] == rightC && (j == 0 || s[j - 1] != rightC))
                        impl(s.substr(0, j) + s.substr(j + 1), i, j, res, fromLeft);
                }
                return;
            }
        }

        std::string t(s);
        std::reverse(t.begin(), t.end());
        if(fromLeft){
            impl(t, 0, 0, res, false);
        }
        else
            res.push_back(t);
    }
};

int main() {
    Solution s;
    //const auto& r = s.removeInvalidParentheses("()())()");
    //const auto& r = s.removeInvalidParentheses(")(");
    //const auto& r = s.removeInvalidParentheses("(((k()((");
    //const auto& r = s.removeInvalidParentheses("(r(()()(");
    const auto& r = s.removeInvalidParentheses(")()())r)");
    for(const auto& i : r)
    {
        std::cout<<i<<std::endl;
    }
}
