#include "header.h"

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        vector<string> words;
        for(int i = 0, n = text.size(); i < n;) {
            if(text[i] == ' ') {
                ++i;                
            } else {
                int j = i;
                while(j < ntext[j] != ' ') ++j;
                const auto& w = text.substr(i, j - i);
                if(words.size() < 2) {
                    words.emplace_back(w);
                } else {
                    if(words[0] == first && words[1] == second) res.emplace_back(w);
                    words[0] = words[1];
                    words[1] = w;
                }
                i = j;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
