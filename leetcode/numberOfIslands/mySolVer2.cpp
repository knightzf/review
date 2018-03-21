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
#include <iterator>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;

        int m = grid.size(), n = grid[0].size();
        vector<int> parent(m * n, -1);

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    if(i > 0 && j > 0 && grid[i - 1][j] == '1' && grid[i][j - 1] == '1')
                    {
                        int p1 = findParent(parent, (i - 1) * n + j);
                        int p2 = findParent(parent, i * n + j - 1);
                        if(p1 != p2)
                        {
                            parent[p2] = p1;
                        }

                        parent[i * n + j] = p1;
                    }
                    else if(i > 0 && grid[i - 1][j] == '1')
                    {
                        parent[i * n + j] = findParent(parent, (i - 1) * n + j);
                    }
                    else if(j > 0 && grid[i][j - 1] == '1')
                    {
                        parent[i * n + j] = findParent(parent, i * n + j - 1);
                    }
                }
                else
                    parent[i * n + j] = -2;
            }
        }

        int cnt = 0;
        for(int p : parent)
            cnt += (p == -1 ? 1 : 0);
        return cnt;
    }
private:
    int findParent(vector<int>& parent, int idx)
    {
        while(parent[idx] != -1)
        {
            idx = parent[idx];
        }
        return idx;
    }
};

int main() {
    Solution s;
    /*vector<vector<char>> a{
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };*/
    vector<vector<char>> a{
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    std::cout<<s.numIslands(a)<<std::endl;
}
