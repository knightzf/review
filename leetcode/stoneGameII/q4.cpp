#include "header.h"

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> sum(n + 1, 0);
        for(int i = 0; i < n; ++i) sum[i + 1] = sum[i] + piles[i];
        map<tuple<int, int, int>, int> mm;
        function<int(int, int, int)> f = [&](int i, int m, int p) {
            if(i == n) return 0;
            auto t = make_tuple(i, m, p);
            auto iter = mm.find(t);
            if(iter != mm.end()) return iter->second;

            int res = 0;
            for(int k = 1; k <= 2 * m; ++k) {
                if(i + k > n) break;
                res = max(res, sum[n] - sum[i] - f(i + k, max(m, k), -p));
            }
            mm[t] = res;
            return res;
        };
        return f(0, 1, 1);
    }
};

int main()
{
    Solution s;
}
