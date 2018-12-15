#include "header.h"

class Solution {
public:

    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        unordered_map<int, int> dp;
        dp[0] = 0;
        for(int i = 1; i < 5000; ++i) dp[i] = -10000;

        for(int rod: rods)
        {
            unordered_map<int, int> prev = dp;
            for(int d = 0; d + rod < 5000; ++d)
            {
                dp[d + rod] = max(dp[d + rod], prev[d]);
                dp[abs(d - rod)] = max(dp[abs(d - rod)], prev[d] + min(d, rod));
            }
        }
        return dp[0];
    }
};

int main()
{
    Solution s;
    //vector<int> a{1,2,4,8,16,32,64,128,256,512,50,50,50,150,150,150,100,100,100,123};
    //vector<int> a{1,2,3,6};
    //vector<int> a{1,2,3,4,5,6};
    //vector<int> a{111,96,96,92,97,90,111,101,112,96,93,91,114};
    vector<int> a{33,30,41,34,37,29,26,31,42,33,38,27,33,31,35,900,900,900,900,900};
    cout<<s.tallestBillboard(a)<<endl;
}
