#include "header.h"

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> t; t.reserve(n);
        for(int x : nums) t.push_back(a * x * x + b * x + c);
        vector<int> res(n);
        if(a >= 0) {
            int i = 0, j = n - 1, k = n - 1;
            while(i <= j) {
                if(t[i] >= t[j]) res[k--] = t[i++];
                else res[k--] = t[j--];
            }
        } else {
            int i = 0, j = n - 1, k = 0;
            while(i <= j) {
                if(t[i] <= t[j]) res[k++] = t[i++];
                else res[k++] = t[j--];
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}