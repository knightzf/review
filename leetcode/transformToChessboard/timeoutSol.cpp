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
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        std::set<vector<vector<int>>> visited;
        visited.insert(board);
        std::queue<vector<vector<int>>> q;
        q.push(board);
        int qsize = 1;
        int steps = 0;

        while(!q.empty())
        {
            for(int i = 0; i < qsize; ++i)
            {
               const auto& b = q.front();
               if(isValid(b)) return steps;

                for(int j = 0; j < n; ++j)
                {
                    for(int k = j + 1; k < n; ++k)
                    {
                        vector<vector<int>> t = b;
                        std::swap(t[j], t[k]);
                        if(visited.find(t) == visited.end())
                        {
                            q.push(t);
                            visited.insert(t);
                        }
                    }
                }

                for(int j = 0; j < n; ++j)
                {
                    for(int k = j + 1; k < n; ++k)
                    {
                        vector<vector<int>> t = b;
                        swap(t, j, k);
                        if(visited.find(t) == visited.end())
                        {
                            q.push(t);
                            visited.insert(t);
                        }
                    }
                }

                q.pop();
            }

            qsize = q.size();
            ++steps;
        }

        return -1;
    }

private:
    void swap(vector<vector<int>>& board, int i, int j)
    {
        int n = board.size();
        for(int k = 0; k < n; ++k)
        {
            std::swap(board[k][i], board[k][j]);
        }
    }

    bool isValid(const vector<vector<int>>& board)
    {
        int n = board.size();
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int v = board[i][j];
                if(i > 0)
                {
                    if(board[i - 1][j] == v)
                    {
                        return false;
                    }
                }
                if(i < n - 1)
                {
                    if(board[i + 1][j] == v)
                    {
                        return false;
                    }
                }
                if(j > 0)
                {
                    if(board[i][j - 1] == v)
                    {
                        return false;
                    }
                }
                if(j < n - 1)
                {
                    if(board[i][j + 1] == v)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> a{{0,1,1,0},{0,1,1,0},{1,0,0,1},{1,0,0,1}};
    std::cout<<s.movesToChessboard(a)<<std::endl;
}
