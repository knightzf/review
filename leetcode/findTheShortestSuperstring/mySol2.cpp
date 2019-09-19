#include "header.h"

class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> overlap(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                overlap[i][j] = calcOverlap(A[i], A[j]);
            }
        }

        vector<vector<int>> dp(1 << n, vector<int>(n, 0));
        vector<vector<int>> parent(1<<n, vector<int>(n, -1));

        for(int s = 1; s < (1 << n); ++s) {
            for(int i = 0; i < n; ++i) {
                if(s & (1 << i)) {
                    int prev = s ^ (1 << i);
                    if(prev == 0) continue;
                    for(int j = 0; j < n; ++j) {
                        if(prev & (1 << j)) {
                            int val = dp[prev][j] + overlap[j][i];
                            if(val > dp[s][i]) {
                                dp[s][i] = val;
                                parent[s][i] = j;
                            }
                        }
                    }
                }
            }
        }

        vector<int> perm;
        vector<bool> seen(n, false);
        int state = (1 << n) - 1;
        int p = 0;
        for(int i = 0; i < n; ++i) {
            if(dp[state][i] > dp[state][p]) {
                p = i;
            }
        }

        while(p != -1) {
            perm.push_back(p);
            seen[p] = true;
            int t = parent[state][p];
            state ^= (1 << p);
            p = t;
        }
        reverse(perm.begin(), perm.end());
        for(int i = 0; i < n; ++i) {
            if(!seen[i]) perm.push_back(i);
        }

        string res = A[perm[0]];
        for(int i = 1; i < n; ++i) {
            int over = overlap[perm[i - 1]][perm[i]];
            res += A[perm[i]].substr(over);
        }
        return res;
    }

    int calcOverlap(const string& a, const string& b) {
        if(a.find(b) != string::npos) return 0;
        for(int m = a.size(), n = b.size(), len = min(m, n); len > 0; --len) {
            if(a.substr(m - len) == b.substr(0, len))
                return len;
        }
        return 0;
    }
};

int main()
{
    //Solution s;
}