#include "header.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
		int n = nums.size();
		vector<int> v;
		function<void(int)> dfs = [&](int idx)
		{
			if(idx == n) return;
			res.emplace_back(v);
			for(int i = idx; i < n; ++i)
			{
				v.emplace_back(nums[i]);
				dfs(i + 1);
				v.pop_back();
			}
		};

		dfs(0);

		return res;
    }
};


int main()
{
    Solution s;
}