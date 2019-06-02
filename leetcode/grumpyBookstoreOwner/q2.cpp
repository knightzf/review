#include "header.h"

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int res = 0;
        for(int i = 0; i < n; ++i) {
            if(!grumpy[i]) res += customers[i];
        }
        for(int i = 0, j = 0, t = res; i < n; ++i)
        {   
            if(i - j + 1 > X) {
                if(grumpy[j]) t -= customers[j];
                ++j;                
            } 
            if(grumpy[i]) {
                t += customers[i];
            }
            res = max(res, t);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{1,0,1,2,1,1,7,5};
    vector<int> b{0,1,0,1,0,1,0,1};
    s.maxSatisfied(a, b, 3);
}
