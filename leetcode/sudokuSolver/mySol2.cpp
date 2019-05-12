#include "header.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>> v;
        int n = 9;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == '.') v.emplace_back(make_pair(i, j));
            }
        }

        function<bool(int)> validSquare = [&](int i)
        {
            vector<bool> visited(n + 1, false);
            int x = (i / 3) * 3;
            int y = (i % 3) * 3;
            for(int i = x; i < x + 3; ++i)
            {
                for(int j = y; j < y + 3; ++j)
                {
                    if(board[i][j] != '.') {
                        if(visited[board[i][j] - '0']) return false;
                        visited[board[i][j] - '0'] = true;
                    }
                }
            }
            return true;
        };

        function<bool(int)> validCol = [&](int i)
        {
            vector<bool> visited(n + 1, false);
            for(int j = 0; j < n; ++j) {
                if(board[j][i] != '.') {
                    if(visited[board[j][i] - '0']) return false;
                    visited[board[j][i] - '0'] = true;
                }
            }
            return true;
        };

        function<bool(int)> validRow = [&](int i)
        {
            vector<bool> visited(n + 1, false);
            for(int j = 0; j < n; ++j) {
                if(board[i][j] != '.') {
                    if(visited[board[i][j] - '0']) return false;
                    visited[board[i][j] - '0'] = true;
                }
            }
            return true;
        };

        function<bool()> validBoard = [&]()
        {
            for(int i = 0; i < n; ++i) if(!validRow(i)) return false;
            for(int i = 0; i < n; ++i) if(!validCol(i)) return false;
            for(int i = 0; i < n; ++i) if(!validSquare(i)) return false;
            return true;
        };

        function<bool(int)> dfs = [&](int i)
        {
            for(const auto& a : board)
            {
                for(const auto& b : a)
                {
                    cout<<b<<" ";
                }
                cout<<endl;
            }
            cout<<"---------"<<endl;
            if(!validBoard()) return false;
            if(i == v.size()) return true;
            for(int j = 1; j < n + 1; ++j)
            {
                board[v[i].first][v[i].second] = '0' + j;
                if(dfs(i + 1)) return true;
                board[v[i].first][v[i].second] = '.';
            }
            return false;
        };

        dfs(0);
    }
};

int main()
{
    Solution s;
    vector<vector<char>> a{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    s.solveSudoku(a);
}