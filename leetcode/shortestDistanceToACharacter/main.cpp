#include "header.h"

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        set<int> pos;
        int n = S.size();
        for(int i = 0; i < n; ++i)
        {
            if(S[i] == C) pos.insert(i);
        }

        vector<int> res(n, 0);
        for(int i = 0; i < n; ++i)
        {
            if(S[i] != C)
            {
                auto iter = pos.lower_bound(i);
                if(iter == pos.end())
                {
                    res[i] = i - *pos.rbegin();
                }
                else
                {
                    res[i] = *iter - i;
                    if(iter != pos.begin())
                    {
                        --iter;
                        res[i] = min(res[i], i - *iter);
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    const auto& r = s.shortestToChar("loveleetcode", 'e');
    for(int i : r) std::cout<<i<<" ";
    std::cout<<std::endl;
}
