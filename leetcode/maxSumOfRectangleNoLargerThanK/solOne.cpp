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
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;

        if(m > n)
        {
            std::swap(m, n);
            vector<vector<int>> t(m, vector<int>(n));
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    t[i][j] = matrix[j][i];
                }
            }
            matrix = t;
        }

        int maxSum = INT_MIN;

        for(int i = 0; i < n; ++i)
        {
            vector<int> sum(m, 0);
            for(int j = i; j < n; ++j)
            {
                for(int l = 0; l < m; ++l)
                {
                    sum[l] += matrix[l][j];
                }

                std::set<int> s{0};
                int currSum = 0;
                for(auto x : sum)
                {
                    currSum += x;
                    auto iter = s.lower_bound(currSum - k);
                    if(iter != s.end())
                        maxSum = max(maxSum, currSum - *iter);
                    s.insert(currSum);
                }
            }
        }

        return maxSum;
    }
};



int main() {
    Solution s;
    vector<vector<int>> a{
        {5, -4, -3, 4},
        {-3, -4, 4, 5},
        {5, 1, 5, 4},
    };

    std::cout<<s.maxSumSubmatrix(a, 10)<<std::endl;;
}
