// Didn't edit the code to make it concise, but the idea is same

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        int n = nums.size();
        {
            int l = 0, h = n - 1;
            while (l <= h) {
                int m = (l + h) / 2;
                if (nums[m] >= target) {
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }
            if (l < n && nums[l] == target) {
                res[0] = l;
            }
        }
        {
            int l = 0, h = n - 1;
            while (l <= h) {
                int m = (l + h) / 2;
                if (nums[m] > target) {
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }
            if (h >= 0 && nums[h] == target) {
                res[1] = h;
            }
        }
        return res;
    }
};
