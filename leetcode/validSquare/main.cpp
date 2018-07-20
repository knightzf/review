#include "header.h"

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> v{p1, p2, p3, p4};
        sort(v.begin(), v.end(), [](const auto& a, const auto& b){
                if(a[0] < b[0]) return true;
                if(a[0] == b[0]) return a[1] < b[1];
                return false;
             });

        if(v[0][0] + v[3][0] != v[1][0] + v[2][0] || v[0][1] + v[3][1] != v[1][1] + v[2][1]) return false;
        int t = (v[3][1] - v[0][1]) * (v[3][1] - v[0][1]) + (v[3][0] - v[0][0]) * (v[3][0] - v[0][0]);
        if(t == 0 || t !=
           (v[2][1] - v[1][1]) * (v[2][1] - v[1][1]) + (v[2][0] - v[1][0]) * (v[2][0] - v[1][0])) return false;
        if((v[3][1] - v[0][1]) * (v[2][1] - v[1][1]) != -1 * (v[3][0] - v[0][0]) * (v[2][0] - v[1][0])) return false;
        return true;
    }
};

int main()
{
    Solution s;
}
