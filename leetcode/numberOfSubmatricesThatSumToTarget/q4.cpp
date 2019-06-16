#include "header.h"

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 1; i < m; ++i)
        {
            for(int j = 0; j < n; ++j) {
                matrix[i][j] += matrix[i - 1][j];
            }
        }
        int res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = i; j < m; ++j) {
                int curr = 0;
                unordered_map<int, int> m{{0, 1}};
                for(int k = 0; k < n; ++k) {
                    int t = 0;
                    if(i == 0) t = matrix[j][k];
                    else t = matrix[j][k] - matrix[i - 1][k];
                    curr += t;
                    if(m.count(curr - target)) {
                        res += m[curr - target];
                    }
                    ++m[curr];
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
    cout<<s.numSubmatrixSumTarget(a, 0);
}
