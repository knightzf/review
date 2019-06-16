#include "header.h"

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> visited(m, false);
        int res = 1;
        for(int i = 0; i < m; ++i) {
            if(!visited[i]) {
                visited[i] = true;
                int cnt = 1;
                for(int j = i + 1; j < m; ++j) {
                    if(matrix[i] == matrix[j] || opp(matrix[i], matrix[j])) {
                        visited[j] = true;
                        ++cnt;
                    }
                }
                res = max(res, cnt);
            }
        }
        return res;
    }

    bool opp(const vector<int>& a, const vector<int>& b) {
        bool res = true;
        for(int i = 0; i < a.size(); ++i) {
            res &= a[i] ^ b[i];
            if(!res) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
}
