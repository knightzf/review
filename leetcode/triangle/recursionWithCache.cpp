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
#include <cstring>
#include <memory>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        m_level = triangle.size();

        if(m_level == 0)
        {
            return 0;
        }

        return impl(triangle, 0, 0);
    }

    int impl(vector<vector<int>>& triangle, int level, int index)
    {
        auto key = std::make_pair(level, index);
        if(cache.find(key) != cache.end())
        {
            return cache[key];
        }

        int val = triangle[level][index];
        int min = level < m_level - 1 ?
            std::min(impl(triangle, level + 1, index), impl(triangle, level + 1, index + 1)) : 0;

        cache[key] = val + min;

        return val + min;
    }

private:
    int m_level;
    std::map<std::pair<int, int>, int> cache;
};

int main()
{
    Solution s;
    vector<vector<int>> a{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    std::cout<< s.minimumTotal(a)<<std::endl;
}
