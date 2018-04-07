#include "header.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        for(int i = 0; i < n;)
        {
            int startIdx = i, endIdx = i;
            int len = words[startIdx].size();;
            int j = startIdx + 1;
            for(; j < n; ++j)
            {
                if(len + words[j].size() + j - startIdx <= maxWidth)
                {
                    ++endIdx;
                    len += words[j].size();
                }
                else break;
            }
            if(endIdx == startIdx)
            {
                res.push_back(words[startIdx] + std::string(maxWidth - words[startIdx].size(), ' '));
            }
            else
            {
                string t;
                if(endIdx == n - 1)
                {
                    for(int k = startIdx; k <= endIdx; ++k)
                    {
                        if(k == startIdx) t += words[k];
                        else t += ' ' + words[k];
                    }
                    t += string(maxWidth - t.size(), ' ');
                }
                else
                {
                    int avgSpace = (maxWidth - len) / (endIdx - startIdx);
                    int extraSpace = (maxWidth - len) % (endIdx - startIdx);

                    for(int k = startIdx; k <= endIdx; ++k)
                    {
                        if(k == startIdx) t += words[k];
                        else
                        {
                            if(extraSpace)
                            {
                                t += string(avgSpace + 1, ' ') + words[k];
                                --extraSpace;
                            }
                            else
                            {
                                t += string(avgSpace, ' ') + words[k];
                            }
                        }
                    }
                }
                res.emplace_back(t);
            }
            i = endIdx + 1;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> a{""};
    const auto& r = s.fullJustify(a, 0);
    std::cout<<r.size()<<std::endl;
}
