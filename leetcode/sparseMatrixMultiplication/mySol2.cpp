#include "header.h"

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = A[0].size(), k = B[0].size();
        vector<vector<int>> res(m, vector<int>(k, 0));
        unordered_map<int, vector<pair<int, int>>> va, vb;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(A[i][j]) {
                    va[i].emplace_back(make_pair(j, A[i][j]));
                }
            }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < k; ++j) {
                if(B[i][j]) {
                    vb[i].emplace_back(make_pair(j, B[i][j]));
                }
            }

        for(const auto& v : va) {
            for(const auto& p : v.second) {
                for(const auto& q : vb[p.first]) {
                    res[v.first][q.first] += p.second * q.second;
                }
            }
        }
        return res;
    }
};

int main()
{
    //Solution s;
}