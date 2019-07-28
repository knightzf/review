#include "header.h"

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        vector<int> sum(n + 1, 0);
        for(int i = 0; i < n; ++i) sum[i + 1] = sum[i] + A[i];
        deque<int> d;
        int res = n + 1;
        for(int i = 0; i < n; ++i) {
            while(!d.empty() && sum[i + 1] - sum[d.front() + 1] >= K) {
                res = min(res, i - d.front());
                d.pop_front();
            }
            while(!d.empty() && sum[i + 1] <= sum[d.back() + 1]) d.pop_back();
            d.push_back(i);
        }
        return res <= n ? res : -1;
    }
};

int main()
{
    Solution s;
    /*vector<int> a{2, -1, 2};
    cout<<s.shortestSubarray(a, 3)<<endl;
     */
    vector<int> a{84,-37,32,40,95};
    cout<<s.shortestSubarray(a, 167)<<endl;
}