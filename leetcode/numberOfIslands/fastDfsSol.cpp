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
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();

        int count = 0;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    ++count;
                    dfs(grid, i, j, m, n);
                    /*
                    std::queue<std::pair<int, int>> q;
                    q.push(std::make_pair(i,j));

                    while(!q.empty())
                    {
                        const auto& p = q.front();
                        grid[p.first][p.second] = 'x';

                        if(p.first > 0 && grid[p.first - 1][p.second] == '1') q.push(std::make_pair(p.first - 1, p.second));
                        if(p.first < m - 1 && grid[p.first + 1][p.second] == '1') q.push(std::make_pair(p.first + 1, p.second));
                        if(p.second > 0 && grid[p.first][p.second - 1] == '1') q.push(std::make_pair(p.first, p.second - 1));
                        if(p.second < n - 1 && grid[p.first][p.second + 1] == '1') q.push(std::make_pair(p.first, p.second + 1));

                        q.pop();
                    }*/
                }
            }
        }

        return count;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n)
    {
        grid[i][j] = '0';
        if(i > 0 && grid[i - 1][j] == '1') dfs(grid, i - 1, j, m, n);
        if(i < m - 1 && grid[i + 1][j] == '1') dfs(grid, i + 1, j, m, n);
        if(j > 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1, m, n);
        if(j < n - 1 && grid[i][j + 1] == '1') dfs(grid, i, j + 1, m, n);
    }
};

int main() {
    Solution s;
    vector<vector<char>> a{{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0'},{'1','0','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1'},{'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}};
    std::cout<<s.numIslands(a)<<std::endl;
}