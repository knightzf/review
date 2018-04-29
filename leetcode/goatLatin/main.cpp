#include "header.h"

class Solution {
public:
    string toGoatLatin(string S) {
        string res;
        int n = S.size();
        int startIdx = 0;
        int cnt = 1;
        for(int i = 0; i <= n; ++i)
        {
            if(i == n || S[i] == ' ')
            {
                const auto& subStr = S.substr(startIdx, i - startIdx);
                if(!subStr.empty())
                {
                    string t = subStr;
                    if(!isVowel(subStr[0]))
                        t = subStr.substr(1) + subStr[0];
                    t += "ma" + string(cnt, 'a');

                    res += (res.empty() ? "" : " ") + t;
                }
                startIdx = i + 1;
                ++cnt;
            }
        }
        return res;
    }

    bool isVowel(char c)
    {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

int main()
{
    Solution s;
    std::cout<<s.toGoatLatin("I speak Goat Latin")<<std::endl;
    std::cout<<s.toGoatLatin("The quick brown fox jumped over the lazy dog")<<std::endl;
}
