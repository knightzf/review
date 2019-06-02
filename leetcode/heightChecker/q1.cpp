#include "header.h"

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> t(heights.begin(), heights.end());
        sort(t.begin(), t.end());
        int res = 0;
        for(int i = 0, n = heights.size(); i < n; ++i) {
            if(heights[i] != t[i]) ++res;
        }
        return res;        
    }
};

int main()
{
    Solution s;
}
