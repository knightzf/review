#include "header.h"

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactDict;
        unordered_map<string, vector<string>> capitalDict;
        unordered_map<string, vector<string>> vowelDict;

        for(const auto& w : wordlist)
        {
            exactDict.insert(w);

            string t;
            std::transform(w.begin(), w.end(), back_inserter(t), ::tolower);
            capitalDict[t].push_back(w);

            string s;
            std::transform(t.begin(), t.end(), back_inserter(s), [](char c){ 
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return '*';
                return c;
            });
            vowelDict[s].push_back(w);
        }

        vector<string> res;
        for(const auto& w : queries)
        {
            if(exactDict.count(w))
            {
                res.push_back(w);
                continue;
            }

            string t;
            std::transform(w.begin(), w.end(), back_inserter(t), ::tolower);
            if(capitalDict.count(t))
            {
                res.push_back(capitalDict[t][0]);
                continue;
            }

            string s;
            std::transform(t.begin(), t.end(), back_inserter(s), [](char c){ 
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return '*';
                return c;
            });

            if(vowelDict.count(s))
            {
                res.push_back(vowelDict[s][0]);
                continue;
            }

            res.push_back("");
        }

        return res;
    }
};

int main()
{
    Solution s;
}

