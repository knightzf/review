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

class NumMatrix {
private:
    int m, n;
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>> matrix) {
        m = matrix.size();
        n = 0;
        if(m > 0)
        {
            n = matrix[0].size();
        }

        dp = vector<vector<int>>(m, vector<int>(n , 0));

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(j == 0)
                {
                    dp[i][j] = matrix[i][j];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + matrix[i][j];
                }
            }
        }

    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for(int i = row1; i <= row2; ++i)
        {
            if(col1 == 0)
            {
                res += dp[i][col2];
            }
            else
            {
                res += dp[i][col2] - dp[i][col1 - 1];
            }
        }
    }
};

class NumArray {
private:
    int n;
    vector<int> dp;
public:
    NumArray(vector<int> nums) {
        n = nums.size();
        dp = vector<int>(n, 0);
        for(int i = 0; i < n; ++i)
        {
            dp[i] = (i == 0 ? nums[0] : dp[i - 1] + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        if(i == 0) return dp[j];
        return dp[j] - dp[i - 1];
    }
};
int main() {
    //Solution s;
}
