#include "header.h"

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        vector<int> B(n + 1, 0);
        for(int i = 0; i < n; ++i)
            B[i + 1] = B[i] + A[i];
        deque<int> q;
        int res = n + 1;
        for(int i = 0; i < n + 1; ++i)
        {
            while(!q.empty() && B[i] - B[q.front()] >= K)
            {
                res = min(res, i - q.front());
                q.pop_front();
            }

            while(!q.empty() && B[i] < B[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        return res == n + 1 ? -1 : res;
    }
};

int main()
{
    Solution s;
}
