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

        function<bool(int, int, int)> validBoard = [&](int x, int y, char c)
        {
            for(int i = 0; i < n; ++i) if(board[x][i] == c || board[i][y] == c) return false;
            int xTop = (x / 3) * 3;
            int yTop = (y / 3) * 3;
            for(int i = xTop; i < xTop + 3; ++i)
            {
                for(int j = yTop; j < yTop + 3; ++j)
                {
                    if(board[i][j] == c) return false;
                }
            }
            return true;
        };

        function<bool(int)> dfs = [&](int i)
        {
            for(const auto& a : board)
            {
                for(const auto& b : a)
                    cout<<b<<" ";
                cout<<endl;
            }
            cout<<"-----"<<endl;
            if(i == v.size()) return true;
            for(int j = 1; j < n + 1; ++j)
            {
                if(!validBoard(v[i].first, v[i].second, '0' + j)) continue;
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