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
    int totalNQueens(int n)
    {
        int total = 0;
        std::vector<std::string> matrix(n, std::string(n, '.'));
        solveNQueens(matrix, 0, total);
        return total;
    }

    void solveNQueens(std::vector<std::string>& matrix, int row, int& total)
    {
        int n = matrix.size();

        for(int i = 0; i < n; ++i)
        {
            matrix[row][i] = 'Q';
            if(isValid(matrix, row))
            {
                if(row == n - 1)
                {
                    ++total;
                }
                else
                {
                    solveNQueens(matrix, row + 1, total);
                }
            }
            matrix[row][i] = '.';
        }
    }

private:
    bool isValid(const std::vector<std::string>& v, int idx)
    {
        for(int i = 0; i <= idx; ++i)
        {
            auto idx = v[i].find('Q');
            if(idx != std::string::npos)
            {
                if(!isValid(v, i, idx))
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isValid(const std::vector<std::string>& v, int i, int j)
    {
        int n = v.size();

        for(int k = 0; k < i; ++k)
        {
            if(k != i && v[k][j] == 'Q')
                return false;
        }

        int tI = i;
        int tJ = j;

        while(tI > 0 && tJ > 0)
        {
            if(v[--tI][--tJ] == 'Q')
                return false;
        }

        tI = i;
        tJ = j;

        while(tI < n - 1 && tJ > 0)
        {
            if(v[++tI][--tJ] == 'Q')
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    std::cout<<sol.totalNQueens(4)<<std::endl;

    return 0;
}
