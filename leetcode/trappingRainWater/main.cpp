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

using namespace std;

class Solution {
public:
    int trap(vector<int>& height)
    {
        int total = 0;

        int start = -1;
        bool shouldEnd = false;
        for(int i = 0; i < height.size(); ++i)
        {
            if(start == -1)
            {
                if(height[i] >= 1)
                {
                    start = i;
                }
            }
            else
            {
                if(shouldEnd)
                {
                    if(height[i] >= height[start])
                    {
                        total += calc(height, start, i);
                        start = i;
                        shouldEnd = false;
                    }
                }
                else
                {
                    if(height[i] >= height[start])
                    {
                        start = i;
                    }
                    else
                    {
                        shouldEnd = true;
                    }
                }
            }
        }

        std::cout<<"----------"<<std::endl;

        start = -1;
        shouldEnd = false;
        for(int i = height.size() - 1; i >= 0; --i)
        {
            if(start == -1)
            {
                if(height[i] >= 1)
                {
                    start = i;
                }
            }
            else
            {
                if(shouldEnd)
                {
                    if(height[i] > height[start])
                    {
                        total += calc(height, start, i);
                        start = i;
                        shouldEnd = false;
                    }
                }
                else
                {
                    if(height[i] >= height[start])
                    {
                        start = i;
                    }
                    else
                    {
                        shouldEnd = true;
                    }
                }
            }
        }

        return total;
    }

private:
    int calc(vector<int>& height, int i, int j)
    {
        std::cout<<i<<" "<<j<<std::endl;

        if(i > j)
        {
            std::swap(i, j);
        }

        int result = std::min(height[i], height[j]) * (j - i - 1);

        for(int k = i + 1; k < j; ++k)
        {
            if(height[k] > 0)
            {
                result -= height[k];
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    //std::vector<int> a{0,1,0,2,1,0,1,3,2,1,2,1};
    std::vector<int> a{2, 0, 2};
    std::cout<<sol.trap(a)<<std::endl;

    return 0;
}
