#include "header.h"

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return false;
        int sum = 0;
        int maxNum = INT_MIN;
        for(int num : nums)
        {
            sum += num;
            maxNum = max(maxNum, num);
        }
        if(sum % 4 != 0) return false;
        int avg = sum / 4;
        if(maxNum > avg) return false;

        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i)
            if(nums[i] == avg) visited[i] = true;

        return dfs(nums, visited, avg, 0, n, 0);
    }

    bool dfs(vector<int>& nums, vector<bool>& visited, int avg, int idx, int n, int sum)
    {
        bool hasUnvisited = false;
        for(int i = idx; i < n; ++i)
        {
            if(visited[i] == false && sum + nums[i] <= avg)
            {
                visited[i] = true;
                if(dfs(nums, visited, avg, ((sum + nums[i]) == avg ? 0 : (i + 1)), n,
                       ((sum + nums[i]) == avg ? 0 : (sum + nums[i])))) return true;
                visited[i] = false;
                hasUnvisited = true;
            }
        }

        return hasUnvisited == false && sum == 0;
    }
};

int main()
{
    Solution s;
    vector<int> a{5,5,5,5,16,4,4,4,4,4,3,3,3,3,4};
    cout<<s.makesquare(a)<<endl;
}
