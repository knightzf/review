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
    std::vector<int> findPossibleValues(vector<vector<char>>& board, int i, int j)
    {
        int bigI = (i / 3) * 3;
        int bigJ = (j / 3) * 3;

        std::set<int> matrix{1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::set<int> col(matrix);
        std::set<int> row(matrix);

        for(int m = bigI; m < bigI + 3; ++m)
        {
            for(int n = bigJ; n < bigJ + 3; ++n)
            {
                int temp = board[m][n] - '0';
                auto iter = matrix.find(temp);
                if(iter != matrix.end())
                {
                    matrix.erase(iter);
                }
            }
        }

        for(int m = 0; m < 9; ++m)
        {
            int temp = board[i][m] - '0';
            auto iter = row.find(temp);
            if(iter != row.end())
            {
                row.erase(iter);
            }
        }

        for(int m = 0; m < 9; ++m)
        {
            int temp = board[m][j] - '0';
            auto iter = col.find(temp);
            if(iter != col.end())
            {
                col.erase(iter);
            }
        }

        std::set<int> result;
        for(const auto& item : matrix)
        {
            if(col.find(item) != col.end() && row.find(item) != row.end())
            {
                result.insert(item);
            }
        }

        return std::vector<int>(result.begin(), result.end());
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        std::vector<std::vector<std::pair<std::vector<int>, int>>> matrix(9,
            std::vector<std::pair<std::vector<int>, int>>(9, std::make_pair(std::vector<int>{}, -1)));

        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                if(board[i][j] == '.')
                {
                    const auto& result = findPossibleValues(board, i, j);
                    matrix[i][j].first = result;
                }
            }
        }

        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                if(board[i][j] == '.')
                {
                    std::cout<<matrix[i][j].first.size()<<" ";
                }
                else
                {
                    std::cout<<"0 ";
                }
            }
            std::cout<<std::endl;
        }
        std::cout<<"--------------"<<std::endl;

        /*const auto& a = matrix[0][0].first;
        for(const auto i: a)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
        const auto& b = matrix[0][1].first;
        for(const auto i: b)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;*/

        int count = 0;
        for(int i = 0; i < 9; )
        {
            for(int j = 0; j < 9;)
            {
                //std::cout<<i<<" "<<j<<std::endl;

                if(!matrix[i][j].first.empty())
                {
                    if(matrix[i][j].second == matrix[i][j].first.size() - 1)
                    {
                        //std::cout<<i<<" "<<j<<std::endl;
                        bool ignore = true;
                        bool found = false;
                        for(int newI = i; newI >= 0; --newI)
                        {
                            for(int newJ = 8; newJ >= 0; --newJ)
                            {
                                if(ignore)
                                {
                                    if(newJ == j)
                                    {
                                        ignore = false;
                                    }
                                    else
                                    {
                                       continue;
                                    }
                                }

                                if(!matrix[newI][newJ].first.empty())
                                {
                                    /*if(newI == 0 && newJ == 0)
                                    {
                                        std::cout<<"get here "<<matrix[newI][newJ].first.size()<<" "<<matrix[newI][newJ].second<<std::endl;
                                    }*/
                                    std::cout<<"back "<<newI<<" "<<newJ<<" "<<matrix[newI][newJ].second<<std::endl;
                                    if(matrix[newI][newJ].second == matrix[newI][newJ].first.size() - 1)
                                    {
                                        matrix[newI][newJ].second = -1;
                                        board[newI][newJ] = '.';
                                    }
                                    else
                                    {
                                        i = newI;
                                        j = newJ;
                                        found = true;
                                        break;
                                    }
                                }
                            }

                            if(found)
                            {
                                break;
                            }
                        }

                        continue;
                    }
                    else
                    {
                        bool hasMatch = false;
                        for(int idx = matrix[i][j].second + 1; idx < matrix[i][j].first.size(); ++idx)
                        {
                            if(isValid(board, matrix[i][j].first[idx], i, j))
                            {
                                board[i][j] = matrix[i][j].first[idx] + '0';
                                matrix[i][j].second = idx;
                                hasMatch = true;
                                break;
                            }
                        }

                        if(!hasMatch)
                        {
                            matrix[i][j].second = matrix[i][j].first.size() - 1;
                            continue;
                        }
                    }
                }

                ++j;
            }

            ++i;
        }
    }

    bool isValid(vector<vector<char>>& board, int val, int i, int j)
    {
        int bigI = (i / 3) * 3;
        int bigJ = (j / 3) * 3;

        for(int m = bigI; m < bigI + 3; ++m)
        {
            for(int n = bigJ; n < bigJ + 3; ++n)
            {
                if(val == board[m][n] - '0')
                {
                    return false;
                }
            }
        }

        for(int m = 0; m < 9; ++m)
        {
            if(val == board[i][m] - '0')
            {
               return false;
            }
        }

        for(int m = 0; m < 9; ++m)
        {
            if(val == board[m][j] - '0')
            {
                return false;
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
