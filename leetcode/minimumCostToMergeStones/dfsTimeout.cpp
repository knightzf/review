#include "header.h"

class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if(n == 1) return 0;
        if(K > n || (n - K) % (K - 1) != 0) return -1;
        map<vector<int>, int> m;
        int res = INT_MAX;
        function<void(const vector<int>&, int, int)> dfs = [&](const vector<int>& s, int k, int cost)
        {
            if(m.count(s) && m[s] <= cost) return;
            m[s] = cost;

            if(s.size() == k) res = min(res, cost + accumulate(s.begin(), s.end(), 0));

            for(int i = 0, n = s.size(); i <= n - k; ++i)
            {
                vector<int> t; 
                t.reserve(n - k + 1);
                int sum = accumulate(s.begin() + i, s.begin() + i + k, 0);                
                t.insert(t.end(), s.begin(), s.begin() + i);
                t.push_back(sum);
                t.insert(t.end(), s.begin() + i + k, s.end());
                dfs(t, k, cost + sum);
            }
        };
        dfs(stones, K, 0);
        return res;
    }
};


int main()
{
    Solution s;
    //vector<int> a{95,54,31,48,44,96,99,20,51,54,18,85,25,84,91,48,40,72,22};
    vector<int> a{4, 6, 4, 7, 5};
    cout<<s.mergeStones(a,2)<<endl;
}
