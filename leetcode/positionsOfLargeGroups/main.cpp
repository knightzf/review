#include "header.h"

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int n = S.size();
        int startIdx = 0;
        vector<vector<int>> res;
        for(int i = 0; i < n;)
        {
            while(i < n && S[i] == S[startIdx]) ++i;
            if(i - startIdx >= 3)
            {
                res.push_back({startIdx, i - 1});
            }
            startIdx = i;
        }
        return res;
    }
};

int main()
{
    Solution s;
    const auto& r = s.largeGroupPositions("abcdddeeeeaabbbcd");
    for(const auto& p : r)
    {
        std::cout<<p[0]<<" "<<p[1]<<std::endl;
    }
}
