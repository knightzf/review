class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int slowIdx = 0;
            int fastIdx = 0;

            while(true)
            {
                slowIdx = nums[slowIdx];
                fastIdx = nums[fastIdx];
                fastIdx = nums[fastIdx];

                if(slowIdx == fastIdx)
                    break;
            }

            int beginIdx = 0;

            while(nums[beginIdx] != nums[slowIdx])
            {
                beginIdx = nums[beginIdx];
                slowIdx = nums[slowIdx];
            }

            return nums[beginIdx];
        }
};
