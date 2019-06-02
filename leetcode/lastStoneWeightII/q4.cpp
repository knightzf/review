#include "header.h"

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        bitset<1501> dp{1};
        int sum = 0;
        for(int a : stones) {
            sum += a;
            for(int i = 1500; i >= a; --i) {
                dp[i] = dp[i] | dp[i - a];
            }
        }
        int res = sum;
        for(int i = 0; i <= 1500; ++i) {
            res = min(res, abs(sum - dp[i] * i * 2));
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{1,1,2,3,5,8,13,21,34,55,89,14,23,37,61,98};
    //vector<int> a{31,26,33,21,40};
    cout<<s.lastStoneWeightII(a)<<endl;
}
