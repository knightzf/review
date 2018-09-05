#include "header.h"

class Solution {    
public:
    double knightProbability(int N, int K, int r, int c) {
        static vector<pair<int, int>> shifts {
            {-1, -2},
            {-2, -1},
            {-2, 1},
            {-1, 2},
            {1, -2},
            {2, -1},
            {2, 1},
            {1, 2}
        };
        vector<vector<double>> v(N, vector<double>(N, 0));
        v[r][c] = 1.0;
        for(int k = 0; k < K; ++k)
        {
            vector<vector<double>> t(N, vector<double>(N, 0));
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < N; ++j) {
                    if(v[i][j]) {
                        for(int m = 0; m < 8; ++m) {
                            int x = i + shifts[m].first;
                            int y = j + shifts[m].second;
                            if(x >= 0 && x < N && y >= 0 && y < N) {
                                t[x][y] += v[i][j] * 0.125;
                            }
                        }
                    }
                }
            }
            v = t;
        }

        double res = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                res += v[i][j];    
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout<<s.knightProbability(8, 30, 6, 4)<<endl;
}
