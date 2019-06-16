#include "header.h"

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<pair<int, int>> v;
        int n = values.size();
        for(int i = 0; i < n; ++i) v.emplace_back(make_pair(values[i], labels[i]));
        sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });
        unordered_map<int, int> cnt;
        int res = 0;
        for(int i = 0, total = 0; i < n && total < num_wanted; ++i) {
            if(++cnt[v[i].second] <= use_limit) {
                res += v[i].first;
                ++total;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
