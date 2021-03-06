#include "header.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int i = 0;
        for(; i < strs[0].size(); ++i)
        {
            for(int j = 1; j < strs.size(); ++j)
            {
                if(i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

int main()
{
    Solution s;
}