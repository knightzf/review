#include "header.h"

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> v;
        for(const auto& trip : trips) {
            v.emplace_back(make_pair(trip[1], trip[0]));
            v.emplace_back(make_pair(trip[2], -trip[0]));
        }
        sort(v.begin(), v.end(), [](const auto& a, const auto& b){
            if(a.first < b.first) return true;
            if(a.first > b.first) return false;
            return a.second < b.second;
        });
        int curr = 0;
        for(const auto& p : v) {
            curr += p.second;
            if(curr > capacity) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
}
