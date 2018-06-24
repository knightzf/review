#include "header.h"

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();

        deque<pair<int, int>> q{{click[0], click[1]}};
        while(!q.empty())
        {
            const auto& p = q.front();

            if(board[p.first][p.second] == 'M')
            {
                board[p.first][p.second] = 'X';
                break;
            }

            board[p.first][p.second] = 'B';
            vector<pair<int, int>> neighbor;
            int cnt = checkMine(board, p, m, n, neighbor);
            if(cnt == 0)
            {
                for(const auto& x : neighbor)
                    q.push_back(x);
            }
            else
            {
                board[p.first][p.second] = '0' + cnt;
            }

            q.pop_front();
        }
        return board;
    }

    int checkMine(vector<vector<char>>& board, const pair<int, int>& p, int m, int n,
                  vector<pair<int, int>>& neighbor)
    {
        int cnt = 0;
        for(int i = -1; i < 2; ++i)
        {
            for(int j = -1; j < 2; ++j)
            {
                if(i == 0 && j == 0) continue;
                int a = p.first + i;
                int b = p.second + j;
                if(a >= 0 && a < m && b >= 0 && b < n)
                {
                    if(board[a][b] == 'E')
                    {
                        neighbor.emplace_back(make_pair(a, b));
                    }
                    else if(board[a][b] == 'M')
                    {
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
};

int main()
{
    Solution s;
}
