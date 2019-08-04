#include "header.h"

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        vector<int> sum(2 * n + 1, 0);
        for(int i = 0; i < 2 * n; ++i) {
            sum[i + 1] = sum[i] + A[i % n];
        }

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        q.push({0, 0});

        int res = INT_MIN;
        for(int i = 1; i < 2 * n + 1; ++i) {
            while(q.top().second < i - n) q.pop();
            res = max(res, sum[i] - q.top().first);
            q.push({sum[i], i});
        }
        return res;
    }
};


int main()
{
    Solution s;
}