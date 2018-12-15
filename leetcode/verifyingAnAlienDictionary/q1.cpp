#include "header.h"

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, char> m;
        for(int i = 0; i < order.size(); ++i)
        {
            m[order[i]] = 'a' + i;
        }

        for(auto& w : words)
        {
            for(char& c : w)
                c = m[c];
        }

        vector<string> t = words;
        sort(t.begin(), t.end());
        return t == words;
    }
};

int main()
{
    Solution s;
}
