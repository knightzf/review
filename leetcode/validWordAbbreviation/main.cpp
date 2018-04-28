#include "header.h"

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int m = word.size(), n = abbr.size();
        int i = 0, j = 0;
        for(; j < n && i < m;)
        {
            if(isalpha(abbr[j]))
            {
                if(abbr[j] != word[i]) return false;
                ++i; ++j;
            }
            else
            {
                if(abbr[j] == '0') return false;
                int k = j;
                while(k < n && isdigit(abbr[k])) ++k;
                int cnt = std::stoi(abbr.substr(j, k - j));
                i += cnt;
                j = k;
            }
        }

        return i == m && j == n;
    }
};

int main()
{
    Solution s;
    std::cout<<s.validWordAbbreviation("apple", "a2e")<<std::endl;
}
