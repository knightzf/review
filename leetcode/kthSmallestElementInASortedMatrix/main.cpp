#include "header.h"

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> q;
        int n = matrix.size();
        for(int i = 0; i < n; ++i) q.push(make_tuple(matrix[i][0], i, 0));
        int cnt = 0, res = 0;
        while(cnt < k) {
            auto p = q.top();
            q.pop();
            res = get<0>(p);
            ++cnt;
            int i = get<1>(p), j = get<2>(p);
            if(j < n - 1) q.push(make_tuple(matrix[i][j + 1], i, j + 1));
        }
        return res;
    }
};

int main()
{
    Solution s;
}