#include "header.h"

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto& w : words)
        {
            if(match(w, pattern)) {
                res.emplace_back(w);
            }
        }
        return res;
    }

    bool match(string word, const string& pattern)
    {
        if(word.size() != pattern.size()) return false;
        unordered_map<char, char> m;
        vector<bool> mapped(26, false);
        for(int i = 0, n = word.size(); i < n; ++i)
        {
            if(m.count(word[i]) == 0)
            {
                if(mapped[pattern[i] - 'a']) return false;
                m[word[i]] = pattern[i];
                mapped[pattern[i] - 'a'] = true;
            }

            word[i] = m[word[i]];

            if(word[i] != pattern[i]) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
}
