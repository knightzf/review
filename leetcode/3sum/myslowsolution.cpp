#include <vector>
#include <iostream>
#include <tuple>
#include <set>
#include <map>
#include <utility>

using namespace std;

struct Two
{
	Two(int a_, int b_, int aIdx_, int bIdx_):
		a(a_), b(b_), aIdx(aIdx_), bIdx(bIdx_)
	{
		if(a > b)
		{
			swap(a, b);
		}
	}
	
	int a;
	int b;
	size_t aIdx;
	size_t bIdx;
	
	bool operator<(const Two& rhs) const
    {
        return std::tie(a, b) < std::tie(rhs.a, rhs.b);
    }
};


struct Three
{
	Three(int a_, int b_, int c_):
		a(a_), b(b_), c(c_)
	{
		if (a > b) 
		{
			std::swap(a, b);
		}
		if (a > c) 
		{
			std::swap(a, c);
		}
		if (b > c) 
		{
			std::swap(b, c);
		}
	}
	
	int a;
	int b;
	int c;
	
	bool operator<(const Three& rhs) const
    {
        return std::tie(a, b, c) < std::tie(rhs.a, rhs.b, rhs.c);
    }
};

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
	{
		std::map<int, std::set<Two>> partMap;
		
		for(size_t i = 0; i < nums.size(); ++i)
		{
			for(size_t j = i + 1; j < nums.size(); ++j)
			{
				int sum = nums[i] + nums[j];
				auto iter = partMap.find(sum);
				
				if(iter == partMap.end())
				{
					std::set<Two> temp;
					temp.insert(Two(nums[i], nums[j], i, j));
					partMap.insert(std::make_pair(sum, temp));
				}
				else
				{
					iter->second.insert(Two(nums[i], nums[j], i, j));
				}
			}
		}
		
		std::set<Three> results;
		
		for(size_t i = 0; i < nums.size(); ++i)
		{
			int sum = 0 - nums[i];
			
			auto iter = partMap.find(sum);
			
			if(iter != partMap.end())
			{
				auto& sumSet = iter->second;
				
				for(auto& two : sumSet)
				{
					if(two.aIdx != i && two.bIdx != i)
					{
						Three temp(nums[i], two.a, two.b);
						if(results.find(temp) == results.end())
						{
							results.insert(temp);
						}
					}
				}
			}
		}
		
		std::vector<std::vector<int>> resultVec;
		for(auto& temp : results)
		{
			resultVec.push_back(std::vector<int>{temp.a, temp.b, temp.c});
		}
		
		return resultVec;
    }
};

int main()
{
	Solution sol;
	std::vector<int> data{-1, 0, 1, 2, -1, -4};
	sol.threeSum(data);
	return 0;
}