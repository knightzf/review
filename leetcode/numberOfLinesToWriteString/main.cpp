#include "header.h"

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> res{1, 0};
        int n = S.size();
        for(int i = 0; i < n; ++i)
        {
            if(res[1] + widths[S[i] - 'a'] > 100)
            {
                ++res[0];
                res[1] = widths[S[i] - 'a'];
            }
            else
            {
                res[1] += widths[S[i] - 'a'];
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
}
