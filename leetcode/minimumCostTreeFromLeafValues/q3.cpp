#include "header.h"

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int res = INT_MAX;
        vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
        function<int(int, int)> findMax = [&](int i, int j) {
            if(m[i][j] == 0) {
                for(int k = i; k < j; ++k) {
                    m[i][j] = max(m[i][j], arr[k]);
                }
            }
            return m[i][j];
        };

        vector<vector<int>> cost(n + 1, vector<int>(n + 1, INT_MAX));
        function<int(int, int)> dfs = [&](int i, int j) {
            if(i + 1 == j) return 0;
            if(cost[i][j] == INT_MAX) {
                for(int k = i + 1; k < j; ++k) {
                    cost[i][j] = min(cost[i][j], dfs(i, k) + dfs(k, j) + findMax(i, k) * findMax(k, j));
                }
            }
            return cost[i][j];
        };
        return dfs(0, n);
    }
};

int main()
{
    Solution s;
    vector<int> a{6, 2, 4};
    cout<<s.mctFromLeafValues(a)<<endl;
}

