#include "header.h"

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        unordered_map<int, int> m;
        for(const auto& b : bookings) {
            m[b[0] - 1] += b[2];
            m[b[1]] -= b[2];
        }
        vector<int> res(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(m.count(i)) cnt += m[i];
            res[i] = cnt;
        }
        return res;
    }
};

int main()
{
}
