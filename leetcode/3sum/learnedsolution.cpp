#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
	{
        std::vector<std::vector<int>> resultVec;
        
        if(nums.empty())
        {
            return resultVec;
        }
        
		std::sort(nums.begin(), nums.end());

		for(size_t i = 0; i < nums.size() - 2 && nums[i] <= 0; ++i)
		{
			if(i == 0 || (nums[i] != nums[i-1]))
			{
				int first = nums[i];
				
				size_t begin = i + 1;
				size_t end = nums.size() - 1;
				
				int lastSecond = 0;
                bool findMatch = false;
                
				while(begin < end)
				{
					int sum = first + nums[begin] + nums[end];
					
					if(sum < 0)
					{
						++begin;
					}
					else if(sum > 0)
					{
						--end;
					}
					else
					{
						if(!findMatch || nums[begin] != lastSecond)
                        {							
						    resultVec.push_back(std::vector<int>{first, nums[begin], nums[end]});
						    lastSecond = nums[begin];
                            findMatch = true;
                        }
                        
						++begin;
						--end;                        
					}					
				}
			}
		}
		
		return resultVec;
    }
};

int main()
{
	Solution sol;
	std::vector<int> data{-2, 0, 0, 2, 2};
	sol.threeSum(data);
	return 0;
}