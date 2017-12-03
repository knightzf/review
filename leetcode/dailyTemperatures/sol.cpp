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
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int len = temperatures.size();
        std::vector<int> res;
        res.reserve(len);
        for(int i = 0; i < len; ++i)
        {
            int v = temperatures[i];
            int j = i + 1;
            while(j < len && temperatures[j] <= v)
            {
                ++j;
            }

            int steps = j == len ? 0 : j - i;
            res.push_back(steps);
        }
        return res;
    }
};

int main()
{
    Solution s;

}
