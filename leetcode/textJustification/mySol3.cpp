#include "header.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size(), startIdx = 0, len = 0;
        for(int i = 0; i < n; ++i)
        {
            len += words[i].size();
            int cnt = i - startIdx;
            if(i == n - 1 || len + cnt + 1 + words[i + 1].size() > maxWidth)
            {                
                int space = 1, extraSpace = 0;
                if(i != n - 1 && cnt)
                {
                    space = (maxWidth - len) / cnt;
                    extraSpace = (maxWidth - len) % cnt;
                }
                string t;
                for(int j = startIdx; j <= i; ++j)
                {
                    if(j != startIdx) {
                        t += string(space + (extraSpace > 0 ? 1 : 0), ' ');
                        --extraSpace;
                    }
                    t += words[j];
                }
                if(t.size() < maxWidth) t += string(maxWidth - t.size(), ' '); 
                res.emplace_back(t);

                startIdx = i + 1;
                len = 0;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> a{"This", "is", "an", "example", "of", "text", "justification."};
    s.fullJustify(a, 16);
}