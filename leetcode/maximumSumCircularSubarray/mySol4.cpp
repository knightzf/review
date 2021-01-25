class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        vector<int> sum(2 * n + 1, 0);
        for(int i = 1; i < 2 * n + 1; ++i) {
            sum[i] = sum[i - 1] + A[(i -1) % n];
        }
        //for(int i : sum) cout<<i<<" "; cout<<endl;
        deque<int> q;
        int res = INT_MIN;
        for(int i = 0; i < 2 * n + 1; ++i) {
            while(!q.empty() && i - q.front() > n) q.pop_front();
            //if(!q.empty()) cout<<i<<" "<<q.back()<<endl;
            if(!q.empty()) res = max(res, sum[i] - sum[q.front()]);
            while(!q.empty() && sum[i] < sum[q.back()]) q.pop_back();
            q.push_back(i);
        }
        return res;
    }
};
