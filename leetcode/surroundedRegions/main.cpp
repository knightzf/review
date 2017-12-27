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

using namespace std;

class Solution {
public:
    void update(vector<vector<char>>& board,
                const std::pair<int, int>& key,
                std::map<std::pair<int, int>, bool>& visited,
                std::queue<std::pair<int, int>>& q,
                bool& notsurrounded,
                int m,
                int n)
    {
        if(board[key.first][key.second] == 'O')
        {
            if(visited.find(key) == visited.end())
            {
                visited[key];
                q.push(key);
                notsurrounded = notsurrounded ||
                    (key.first == 0 || key.second == 0 || key.first == m - 1 || key.second == n - 1);
            }
        }
    }

    void solve(vector<vector<char>>& board)
    {
        int m = board.size();
        if(m == 0)
        {
            return;
        }
        int n = board[0].size();
        if(n == 0)
        {
            return;
        }

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == 'O')
                {
                    bool notsurrounded = (i == 0 || j == 0 || i == m - 1 || j == n - 1);
                    std::map<std::pair<int, int>, bool> visited;
                    auto key = std::make_pair(i, j);

                    std::queue<std::pair<int, int>> q;
                    q.push(key);

                    while(!q.empty())
                    {
                        const auto& element = q.front();
                        visited[element];

                        if(element.first > 0)
                        {
                            auto key = std::make_pair(element.first - 1, element.second);
                            update(board, key, visited, q, notsurrounded, m, n);
                        }

                        if(element.second > 0)
                        {
                            auto key = std::make_pair(element.first, element.second - 1);
                            update(board, key, visited, q, notsurrounded, m, n);
                        }

                        if(element.first < m - 1)
                        {
                            auto key = std::make_pair(element.first + 1, element.second);
                            update(board, key, visited, q, notsurrounded, m, n);
                        }

                        if(element.second < n - 1)
                        {
                            auto key = std::make_pair(element.first, element.second + 1);
                            update(board, key, visited, q, notsurrounded, m, n);
                        }

                        q.pop();
                    }

                    if(notsurrounded)
                    {
                        for(const auto& key : visited)
                        {
                            board[key.first.first][key.first.second] = 'A';
                        }
                    }
                    else
                    {
                        for(const auto& key : visited)
                        {
                            board[key.first.first][key.first.second] = 'X';
                        }
                    }
                }
            }
        }

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
};

int main()
{
    Solution s;
}
