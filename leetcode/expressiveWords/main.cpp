#include "header.h"

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        vector<pair<char, int>> v;
        int cnt = 0;
        for(int i = 0; i < S.size(); ++i)
        {
            if(i == 0 || S[i] != S[i - 1])
                cnt = 1;
            if(i == S.size() - 1 || S[i] != S[i + 1])
                v.push_back(std::make_pair(S[i], cnt));
            else
                ++cnt;
        }

        /*for(const auto& p : v)
        {
            std::cout<<p.first<<" "<<p.second<<" | ";
        }
        std::cout<<std::endl;*/

        int res = 0;
        for(const auto& word : words)
        {
            int vIdx = 0;
            int cnt = 0;
            bool good = true;
            for(int i = 0; i < word.size(); ++i)
            {
                if(i == 0 || word[i] != word[i - 1])
                    cnt = 1;
                if(i == word.size() - 1 || word[i] != word[i + 1])
                {
                    if(vIdx < v.size() && word[i] == v[vIdx].first &&
                       (cnt == v[vIdx].second || v[vIdx].second >= 3 && cnt < v[vIdx].second))
                        ++vIdx;
                    else
                    {
                        good = false;
                        break;
                    }
                }
                else
                    ++cnt;
            }

            if(good && vIdx == v.size()) ++res;
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<string> a{"hello", "hi", "helo"};
    std::cout<<s.expressiveWords("heeellooo", a)<<std::endl;
}
