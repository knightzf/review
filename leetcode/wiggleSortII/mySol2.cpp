#include "header.h"

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int num = nums[n / 2];
        int i = 1, j = (n & 1) ? n - 1 : n - 2;
        int p = 0;
        while(p < n) {
            if(nums[p] > num && (p > i || (p & 1) == 0)) {
                swap(nums[p], nums[i]);
                i += 2;
            }
            else if(nums[p] < num && (p < j || p & 1)) {
                swap(nums[p], nums[j]);
                j -= 2;
            }
            else ++p;
        }
    }
};

int main()
{
    Solution s;
    //vector<int> a{1,3,2,2,3,1};
    //vector<int> a{1,5,1,1,6,4};
    vector<int> a{1,3,2,2,3,1};
    s.wiggleSort(a);
    for(int i : a) cout<<i<<" ";
    cout<<endl;
}