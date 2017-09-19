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

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for(int i = 0; i < 9; ++i)
        {
            if(!isValid(board, i, true))
            {
                return false;
            }

            if(!isValid(board, i))
            {
                return false;
            }
        }

        for(int i = 0; i < 9; i += 3)
        {
            for(int j = 0; j < 9; j += 3)
            {
                if(!isValid(board, i , j))
                {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool isValid(const vector<vector<char>>& board, int col)
    {
        std::vector<int> map(10, 0);
        for(int i = 0; i < 9; ++i)
        {
            char val = board[i][col];
            if(val == '.')
            {
                continue;
            }

            val = val - '0';
            if(map[val] == 0)
            {
                map[val] = 1;
            }
            else
            {
                return false;
            }
        }

        return true;
    }

    bool isValid(const vector<vector<char>>& board, int row, bool dum)
    {
        std::vector<int> map(10, 0);
        for(int i = 0; i < 9; ++i)
        {
            int val = board[row][i];
            if(val == '.')
            {
                continue;
            }

            val = val - '0';
            if(map[val] == 0)
            {
                map[val] = 1;
            }
            else
            {
                return false;
            }
        }

        return true;
    }

    bool isValid(const vector<vector<char>>& board, int row, int col)
    {
        std::vector<int> map(10, 0);

        for(int i = row; i < row + 3; ++i)
        {
            for(int j = col; j < col + 3; ++j)
            {
                int val = board[i][j];
                if(val == '.')
                {
                    continue;
                }

                val = val - '0';
                if(map[val] == 0)
                {
                    map[val] = 1;
                }
                else
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

    return 0;
}
