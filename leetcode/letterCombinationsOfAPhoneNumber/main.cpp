#include "header.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static unordered_map<char, string> m{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> res;
        function<void(int, string&)> dfs = [&](int idx, string& s)
        {
            if(idx == digits.size() && !s.empty()) 
            {
                res.push_back(s);
                return;
            }

            for(char c : m[digits[idx]])
            {
                s += c;
                dfs(idx + 1, s);
                s.pop_back();
            }
        };

        string t;
        dfs(0, t);
        return res;
    }
};

int main()
{
    Solution s;
}