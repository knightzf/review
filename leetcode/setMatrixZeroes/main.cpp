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

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        if(m == 0)
        {
            return;
        }

        int n = matrix[0].size();
        if(n == 0)
        {
            return;
        }

        bool firstRowZero = false;
        bool firstColZero = false;

        for(int i = 0; i < n; ++i)
        {
            if(matrix[0][i] == 0)
            {
                firstRowZero = true;
                break;
            }
        }

        for(int i = 0; i < m; ++i)
        {
            if(matrix[i][0] == 0)
            {
                firstColZero = true;
                break;
            }
        }

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1; i < m; ++i)
        {
            if(matrix[i][0] == 0)
            {
                for(int j = 1; j < n; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i = 1; i < n; ++i)
        {
            if(matrix[0][i] == 0)
            {
                for(int j = 1; j < m; ++j)
                {
                    matrix[j][i] = 0;
                }
            }
        }

        if(firstRowZero)
        {
            for(int i = 0; i < n; ++i)
            {
                matrix[0][i] = 0;
            }
        }

        if(firstColZero)
        {
            for(int i = 0; i < m; ++i)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    Solution sol;
    return 0;
}
