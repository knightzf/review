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
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> grid(N, vector<int>(N, 1));
        for(const auto& p : mines)
        {
            grid[p[0]][p[1]] = 0;
        }

        vector<vector<int>> left(N, vector<int>(N, 0));
        vector<vector<int>> right(N, vector<int>(N, 0));
        vector<vector<int>> up(N, vector<int>(N, 0));
        vector<vector<int>> down(N, vector<int>(N, 0));

        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                if(grid[i][j])
                {
                    left[i][j] = (j == 0 || grid[i][j - 1] == 0) ? 0 : left[i][j - 1] + 1;
                    up[i][j] = (i == 0 ||  grid[i - 1][j] == 0) ? 0 : up[i - 1][j] + 1;
                }
            }
        }

        for(int i = N - 1; i >= 0; --i)
        {
            for(int j = N - 1; j >= 0; --j)
            {
                if(grid[i][j])
                {
                    right[i][j] = (j == N - 1 || grid[i][j + 1] == 0) ? 0 : right[i][j + 1] + 1;
                    down[i][j] = (i == N - 1 || grid[i + 1][j] == 0) ? 0 : down[i + 1][j] + 1;
                }
            }
        }

        int largestOrder = 0;

        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                if(grid[i][j])
                {
                    int t = std::min(
                                     std::min(left[i][j], right[i][j]),
                                     std::min(up[i][j], down[i][j])
                                     );
                    largestOrder = std::max(largestOrder, t + 1);
                }
            }
        }

        return largestOrder;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a{{4, 2}};
    std::cout<<s.orderOfLargestPlusSign(5, a)<<std::endl;
    vector<vector<int>> b;
    std::cout<<s.orderOfLargestPlusSign(2, b)<<std::endl;
    vector<vector<int>> c{{0, 0}};
    std::cout<<s.orderOfLargestPlusSign(1, c)<<std::endl;
}
