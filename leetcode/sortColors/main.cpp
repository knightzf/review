#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 0)
        {
            return;
        }

        int zeroStart = -1;

        int oneStart = -1;

        int twoStart = -1;

        for(int i = 0; i < n; ++i)
        {
            switch(nums[i])
            {
            case 0:
                {
                    if(oneStart == -1 && twoStart == -1)
                    {
                        if(zeroStart == -1)
                        {
                            zeroStart = i;
                        }
                    }
                    else
                    {
                        if(oneStart == -1 && twoStart != -1)
                        {
                            std::swap(nums[twoStart], nums[i]);
                            if(zeroStart == -1)
                            {
                                zeroStart = twoStart;
                            }
                            ++twoStart;
                        }
                        else if(oneStart != -1 && twoStart == -1)
                        {
                            std::swap(nums[oneStart], nums[i]);
                            if(zeroStart == -1)
                            {
                                zeroStart = oneStart;
                            }
                            ++oneStart;
                        }
                        else
                        {
                            std::swap(nums[twoStart], nums[i]);
                            std::swap(nums[twoStart], nums[oneStart]);
                            if(zeroStart == -1)
                            {
                                zeroStart = oneStart;
                            }
                            ++oneStart;
                            ++twoStart;
                        }
                    }
                    break;
                }
            case 1:
                {
                    if(twoStart == -1)
                    {
                        if(oneStart == -1)
                        {
                            oneStart = i;
                        }
                    }
                    else
                    {
                        std::swap(nums[twoStart], nums[i]);
                        if(oneStart == -1)
                        {
                            oneStart = twoStart;
                        }
                        ++twoStart;
                    }
                    break;
                }
            case 2:
                {
                    if(twoStart == -1)
                    {
                        twoStart = i;
                    }
                    break;
                }
            default:
                break;
            }
        }
    }
};

int main()
{
    Solution sol;
    return 0;
}
