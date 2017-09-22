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
    void updateMatrix(std::vector<std::vector<std::vector<int>>>& matrix, int val, int i, int j)
    {
        int bigI = (i / 3) * 3;
        int bigJ = (j / 3) * 3;

        for(int m = bigI; m < bigI + 3; ++m)
        {
            for(int n = bigJ; n < bigJ + 3; ++n)
            {
                auto& cube = matrix[m][n];
                if(cube.size() > 1)
                {
                    for(auto iter = cube.begin(); iter != cube.end(); ++iter)
                    {
                        if(*iter == val)
                        {
                            cube.erase(iter);
                            break;
                        }
                    }
                }
            }
        }

        for(int m = 0; m < 9; ++m)
        {
            auto& cube = matrix[i][m];
            if(cube.size() > 1)
            {
                for(auto iter = cube.begin(); iter != cube.end(); ++iter)
                {
                    if(*iter == val)
                    {
                        cube.erase(iter);
                        break;
                    }
                }
            }
        }

        for(int m = 0; m < 9; ++m)
        {
            auto& cube = matrix[m][j];
            if(cube.size() > 1)
            {
                for(auto iter = cube.begin(); iter != cube.end(); ++iter)
                {
                    if(*iter == val)
                    {
                        cube.erase(iter);
                        break;
                    }
                }
            }
        }
    }

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

        /*if(i == 6 && j == 4)
        {
            std::cout<<"aaa"<<std::endl;
            std::cout<<bigI<<" "<<bigJ<<std::endl;
            for(const auto& item : matrix)
            {
                std::cout<<item<<" ";
            }
            std::cout<<std::endl;
            for(const auto& item : col)
            {
                std::cout<<item<<" ";
            }
            std::cout<<std::endl;
            for(const auto& item : row)
            {
                std::cout<<item<<" ";
            }
            std::cout<<std::endl;
            std::cout<<"bbb"<<std::endl;
        }*/
        //std::cout<<i<<" "<<j<<" "<<matrix.size()<<" "<<row.size()<<" "<<col.size()<<std::endl;

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
        std::vector<std::vector<std::vector<int>>> matrix(9,
            std::vector<std::vector<int>>(9, std::vector<int>{}));

        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                if(board[i][j] == '.')
                {
                    const auto& result = findPossibleValues(board, i, j);
                    matrix[i][j].insert(matrix[i][j].end(), result.begin(), result.end());
                }
            }
        }

//        for(int i = 0; i < 9; ++i)
//        {
//            for(int j = 0; j < 9; ++j)
//            {
//                const auto& vec = matrix[i][j];
//                if(!vec.empty())
//                {
//                    for(const auto& item : vec)
//                    {
//                        std::cout<<item<<" ";
//                    }
//                    std::cout<<"\t";
//                }
//                else
//                {
//                    std::cout<<"     , ";
//                }
//            }
//            std::cout<<std::endl;
//        }

        /**/for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                const auto& vec = matrix[i][j];
                if(!vec.empty())
                {
                    std::cout<<vec.size()<<" ";
                }
                else
                {
                  std::cout<<"0 ";
                }
            }
            std::cout<<std::endl;
        }
        std::cout<<"====================="<<std::endl;


        /*const auto& t = matrix[2][3];
        for(const auto& item : t)
        {
            std::cout<<item<<" ";
        }
        std::cout<<std::endl;*/

        while(true)
        {
            int count = 0;

            for(int i = 0; i < 9; ++i)
            {
                for(int j = 0; j < 9; ++j)
                {
                    const auto& vec = matrix[i][j];
                    if(vec.size() == 1)
                    {
                        //std::cout<<i<<" "<<j<<" "<<vec[0]<<std::endl;
                        board[i][j] = vec[0] + '0';
                        matrix[i][j].clear();
                        updateMatrix(matrix, vec[0], i, j);
                    }
                    else if(vec.size() > 1)
                    {
                        ++count;
                    }
                }
            }

            /**/for(int i = 0; i < 9; ++i)
            {
                for(int j = 0; j < 9; ++j)
                {
                    std::cout<<board[i][j]<<" ";
                }
                std::cout<<std::endl;
            }

            std::cout<<"--------"<<std::endl;
            for(int i = 0; i < 9; ++i)
            {
                for(int j = 0; j < 9; ++j)
                {
                    const auto& vec = matrix[i][j];
                    if(!vec.empty())
                    {
                        std::cout<<vec.size()<<" ";
                    }
                    else
                    {
                      std::cout<<"0 ";
                    }
                }
                std::cout<<std::endl;
            }

            std::cout<<"||||||||||||||||||||||||||"<<std::endl;


            if(!count)
            {
                break;
            }

            /*const auto& t = matrix[2][3];
            for(const auto& item : t)
            {
                std::cout<<item<<" ";
            }
            std::cout<<std::endl;*/
            //break;

        }
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
    return 0;
}
