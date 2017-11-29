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
#include <unordered_set>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int ret = 0;
        heights.push_back(0);
        std::stack<int> s;

        for(size_t i = 0; i < heights.size(); ++i)
        {
            while(!s.empty() && heights[s.top()] >= heights[i])
            {
                int h = heights[s.top()];
                s.pop();

                int startIdx = s.empty() ? -1 : s.top();
                if((i - startIdx - 1) * h > ret)
                    ret = (i - startIdx - 1) * h;
            }
            s.push(i);
        }

        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 2, 2};
    s.largestRectangleArea(a);
}
