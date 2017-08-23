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

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        size_t max = 0;

        size_t start = 0;
        size_t end = height.size() - 1;

        int currentHeigh = std::max(height[start], height[end]);
        max = currentHeigh * (end - start);

        while(true)
        {
            while(height[start] <= currentHeigh && start < end)
            {
                ++start;
            }

            while(height[end] <= currentHeigh && start < end)
            {
                --end;
            }

            if(start == end)
            {
                break;
            }
            else
            {
                currentHeigh = std::max(height[start], height[end]);
                max = std::max(max, currentHeigh * (end - start));
            }
        }

        return max;
    }
};
int main()
{
    Solution sol;

    return 0;
}
