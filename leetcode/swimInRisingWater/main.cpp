#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
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
#include <iterator>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        std::map<int, std::pair<int, int>> potential;

        potential[grid[0][0]] = {0, 0};

        std::pair<int, int> target{n - 1, n - 1};

        while(true)
        {
            int t = potential.begin()->first;
            while(potential.begin()->first <= t)
            {
                int v = potential.begin()->first;
                const auto& p = potential.begin()->second;

                if(p == target) return t;

                if(p.first > 0 && grid[p.first - 1][p.second] != -1)
                    potential[grid[p.first - 1][p.second]] = {p.first - 1, p.second};
                if(p.first < n - 1 && grid[p.first + 1][p.second] != -1)
                    potential[grid[p.first + 1][p.second]] = {p.first + 1, p.second};
                if(p.second > 0 && grid[p.first][p.second - 1] != -1)
                    potential[grid[p.first][p.second - 1]] = {p.first, p.second - 1};
                if(p.second < n - 1 && grid[p.first][p.second + 1] != -1)
                    potential[grid[p.first][p.second + 1]] = {p.first, p.second + 1};

                potential.erase(v);
                grid[p.first][p.second] = -1;
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a{{3, 2}, {0, 1}};
    s.swimInWater(a);
}
