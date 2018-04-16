#include "header.h"

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedS(banned.begin(), banned.end());
        unordered_map<string, int> cntMap;
        string t;
        for(int i = 0; i < paragraph.size(); ++i)
        {
            if(std::isalpha(paragraph[i]))
            {
                t += std::tolower(paragraph[i]);
            }

            if((!std::isalpha(paragraph[i]) || i == paragraph.size() - 1) && !t.empty())
            {
                if(bannedS.find(t) == bannedS.end()) ++cntMap[t];
                t.clear();
            }
        }

        int maxFreq = 0;
        string res;
        for(const auto& p : cntMap)
        {
            if(p.second > maxFreq)
            {
                maxFreq = p.second;
                res = p.first;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> a{"hit"};
    std::cout<<s.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", a)<<std::endl;
    //vector<string> a{};
    //std::cout<<s.mostCommonWord("Bob", a)<<std::endl;
}
