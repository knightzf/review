#include "header.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> v;
        for(int i = 0; i < numRows; ++i)
        {
            v.insert(v.begin(), 1);
            for(int j = 1, n = v.size(); j < n - 1; ++j)
            {
                v[j] = v[j] + v[j + 1];
            }
            res.emplace_back(v);
        }
        return res;
    }
};

int main()
{
    Solution s;
    
}