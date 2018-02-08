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
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();
        if(n == 0) return;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int c = 0;
                if(i > 0)
                {
                    if(board[i - 1][j] >= 1) ++c;
                    if(j > 0 && board[i - 1][j - 1] >= 1) ++c;
                    if(j < n - 1 && board[i - 1][j + 1] >= 1) ++c;
                }

                if(i < m - 1)
                {
                    if(board[i + 1][j] >= 1) ++c;
                    if(j > 0 && board[i + 1][j - 1] >= 1) ++c;
                    if(j < n - 1 && board[i + 1][j + 1] >= 1) ++c;
                }

                if(j > 0)
                {
                    if(board[i][j - 1] >= 1) ++c;
                }

                if(j < n - 1)
                {
                    if(board[i][j + 1] >= 1) ++c;
                }

                if(board[i][j] == 1)
                {
                    if(c < 2) board[i][j] = 2;
                    if(c > 3) board[i][j] = 2;
                }
                else
                {
                    if(c == 3) board[i][j] = -1;
                }
            }
        }

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == 2) board[i][j] = 0;
                if(board[i][j] == -1) board[i][j] = 1;
            }
        }
    }
};


int main() {
    Solution s;
}
