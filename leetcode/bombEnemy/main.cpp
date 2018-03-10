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
private:
    struct Range{
        Range(){}
        Range(int a, int b, bool c) : horiCnt(a), vertiCnt(b) {}
        int horiCnt;
        int vertiCnt;
    };
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;

        vector<vector<Range>> v(m, vector<Range>(n));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '0')
                {
                    v[i][j].horiCnt = j > 0 ? v[i][j - 1].horiCnt : 0;
                    v[i][j].vertiCnt = i > 0 ? v[i - 1][j].vertiCnt : 0;
                }
                else if(grid[i][j] == 'E')
                {
                    v[i][j].horiCnt = j > 0 ? v[i][j - 1].horiCnt + 1 : 1;
                    v[i][j].vertiCnt = i > 0 ? v[i - 1][j].vertiCnt + 1 : 1;
                }
                else if(grid[i][j] == 'W')
                {
                    v[i][j].horiCnt = 0;
                    v[i][j].vertiCnt = 0;
                }
            }
        }

        /*for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                std::cout<<v[i][j].horiCnt<<" "<<v[i][j].vertiCnt<<std::endl;
            }
        }*/

        int maxCnt = 0;

        for(int i = m - 1; i >= 0; --i)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                if(grid[i][j] == '0' || grid[i][j] == 'E')
                {
                    if(i + 1 < m && v[i + 1][j].vertiCnt > v[i][j].vertiCnt)
                        v[i][j].vertiCnt = v[i + 1][j].vertiCnt;
                    if(j + 1 < n && v[i][j + 1].horiCnt > v[i][j].horiCnt)
                        v[i][j].horiCnt = v[i][j + 1].horiCnt;

                    if(grid[i][j] == '0')
                        maxCnt = max(maxCnt, v[i][j].horiCnt + v[i][j].vertiCnt);
                }
            }
        }

        return maxCnt;
    }
};

int main() {
    Solution s;
    /*vector<vector<char>> a{
        {'0', 'E', '0', '0'},
        {'E', '0', 'W', 'E'},
        {'0', 'E', '0', '0'}
    };*/
    vector<vector<char>> a{
        {'0', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'W'},
    };
    std::cout<<s.maxKilledEnemies(a)<<std::endl;
}
