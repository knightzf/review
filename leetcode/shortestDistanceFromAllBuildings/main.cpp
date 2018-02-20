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
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();

        auto total = grid;

        int walk = 0, minDist;
        int shift[] = {0, 1, 0, -1, 0};

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    minDist = -1;
                    auto dist = grid;
                    std::queue<std::pair<int, int>> q;
                    q.emplace(i, j);
                    while(!q.empty())
                    {
                        auto p = q.front();
                        q.pop();
                        for(int k = 0; k < 4; ++k)
                        {
                            int ii = p.first + shift[k];
                            int jj = p.second + shift[k + 1];

                            if(ii >= 0 && ii < m && jj >= 0 && jj < n && grid[ii][jj] == walk)
                            {
                                --grid[ii][jj];
                                dist[ii][jj] = dist[p.first][p.second] + 1;
                                total[ii][jj] += dist[ii][jj] - 1;
                                q.emplace(ii, jj);

                                if(minDist < 0 || minDist > total[ii][jj])
                                {
                                    minDist = total[ii][jj];
                                }
                            }
                        }
                    }
                    --walk;
                }
            }
        }

        return minDist;
    }
};

int main() {
    Solution s;
}
