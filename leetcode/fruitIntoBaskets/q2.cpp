#include "header.h"

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res = 0;
        int n = tree.size();
        for(int i = 0; i < n;)
        {
            unordered_set<int> s;
            for(int j = i; j < n; ++j)
            {
                s.insert(tree[j]);
                if(s.size() == 3)
                {
                    res = max(res, j - i);
                    --j;
                    int t = tree[j];
                    while(j >= 0 && tree[j] == t) --j;
                    i = j + 1;
                    break;
                }
                else if(j == n - 1)
                {
                    res = max(res, n - i);
                    return res;
                }
            }
        }
        return res;
    }
};

int main()
{
    //Solution s;
}
