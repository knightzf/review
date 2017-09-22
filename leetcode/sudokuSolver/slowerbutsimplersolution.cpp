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

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        std::stack<std::pair<vector<vector<char>>, std::pair<int,int>>> s;

        for(int i = 0; i < 9; ++i)
        {
            bool foundFirst = false;

            for(int j = 0; j < 9; ++j)
            {
                if(board[i][j] == '.')
                {
                    auto temp = board;
                    for(int k = 1; k < 10; ++k)
                    {
                        temp[i][j] = k + '0';
                        if(isValid(temp))
                        {
                            s.push(std::make_pair(temp, std::make_pair(i,j)));
                        }
                    }

                    foundFirst = true;
                    break;
            }
            }

            if(foundFirst)
            {
                break;
            }
        }

        int count = 0;

        while(!s.empty())
        {
            auto temp = s.top();
            s.pop();

            if(isComplete(temp.first))
            {
                board = temp.first;
                return;
            }

            for(int i = temp.second.first; i < 9; ++i)
            {
                bool foundFirst = false;

                for(int j = (i == temp.second.first ? temp.second.second : 0); j < 9; ++j)
                {
                    if(temp.first[i][j] == '.')
                    {
                        auto tboard = temp.first;
                        for(int k = 1; k < 10; ++k)
                        {
                            tboard[i][j] = k + '0';
                            if(isValid(tboard))
                            {
                                s.push(std::make_pair(tboard, std::make_pair(i,j)));
                            }
                        }

                        foundFirst = true;
                        break;
                    }
                }

                if(foundFirst)
                {
                    break;
                }
            }
        }
    }

    bool isValid(const vector<vector<char>>& board)
    {
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                std::bitset<10> bs;

                int bigI = (i / 3) * 3;
                int bigJ = (j / 3) * 3;

                for(int m = bigI; m < bigI + 3; ++m)
                {
                    for(int n = bigJ; n < bigJ + 3; ++n)
                    {
                        if(board[m][n] == '.')
                            continue;

                        int val = board[m][n] - '0';
                        if(bs[val])
                        {
                            return false;
                        }
                        else
                        {
                            bs[val] = true;
                        }
                    }
                }

                bs.reset();

                for(int m = 0; m < 9; ++m)
                {
                    if(board[i][m] == '.')
                        continue;

                    int val = board[i][m] - '0';
                    if(bs[val])
                    {
                        return false;
                    }
                    else
                    {
                        bs[val] = true;
                    }
                }

                bs.reset();

                for(int m = 0; m < 9; ++m)
                {
                    if(board[m][j] == '.')
                        continue;

                    int val = board[m][j] - '0';
                    if(bs[val])
                    {
                        return false;
                    }
                    else
                    {
                        bs[val] = true;
                    }
                }
            }
        }

        return true;
    }

    bool isComplete(const vector<vector<char>>& board)
    {
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                if(board[i][j] == '.')
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> board
    {
        {'.', '.', '9', '7', '4', '8', '.', '.', '.'},
        {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '2', '.', '1', '.', '9', '.', '.', '.'},
        {'.', '.', '7', '.', '.', '.', '2', '4', '.'},
        {'.', '6', '4', '.', '1', '.', '5', '9', '.'},
        {'.', '9', '8', '.', '.', '.', '3', '.', '.'},
        {'.', '.', '.', '8', '.', '3', '.', '2', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '6'},
        {'.', '.', '.', '2', '7', '5', '9', '.', '.'}
    };

    sol.solveSudoku(board);

    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            std::cout<<board[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}
