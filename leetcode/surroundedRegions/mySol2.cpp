#include "header.h"

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int m = board.size(), n = board[0].size();
        function<void(int, int)> dfs = [&](int i, int j) 
        {
            static vector<int> diff{-1, 0, 1, 0, -1};
            board[i][j] = 'a';            
            for(int k = 0; k < 4; ++k) {
                int x = i + diff[k], y = j + diff[k + 1];
                if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {
                    dfs(x, y);
                }
            }
        };

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O') {
                    dfs(i, j);
                }
            }
        }

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'a') board[i][j] = 'O';
            }
        }
    }
};


int main()
{
    Solution s;
    
}