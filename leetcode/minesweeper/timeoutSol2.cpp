#include "header.h"

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> mines(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == 'M')
                {
                    for(int a = -1; a < 2; ++a)
                    {
                        for(int b = -1; b < 2; ++b)
                        {
                            if(a == 0 && b == 0) continue;
                            int c = i + a;
                            int d = j + b;
                            if(c >= 0 && c < m && d >= 0 && d < n && board[c][d] == 'E')
                            {
                                ++mines[c][d];
                            }
                        }
                    }
                }
            }
        }

        deque<pair<int, int>> q{{click[0], click[1]}};
        while(!q.empty())
        {
            const auto& p = q.front();

            if(board[p.first][p.second] == 'M')
            {
                board[p.first][p.second] = 'X';
                break;
            }

            if(mines[p.first][p.second])
            {
                board[p.first][p.second] = '0' + mines[p.first][p.second];
            }
            else
            {
                board[p.first][p.second] = 'B';
                for(int i = -1; i < 2; ++i)
                {
                    for(int j = -1; j < 2; ++j)
                    {
                        if(i == 0 && j == 0) continue;
                        int a = p.first + i;
                        int b = p.second + j;
                        if(a >= 0 && a < m && b >= 0 && b < n && board[a][b] == 'E')
                        {
                            if(mines[a][b])
                                board[a][b] = '0' + mines[a][b];
                            else
                                q.push_back(make_pair(a, b));
                        }
                    }
                }
            }

            q.pop_front();
        }
        return board;
    }
};

int main()
{
    Solution s;
}
