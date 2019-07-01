#include "header.h"

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<pair<int, int>> range;
        range.push_back(make_pair(1, 1));
        int p = 1;
        while(range.back().second < label) {
            range.push_back(make_pair(1 << p, range.back().second + (1 << p)));
            ++p;
        }
        vector<int> res;
        for(int i = range.size() - 1; i > 0; --i) {
            res.push_back(label);
            int idx = range[i].second - label;
            if(i & 1) {
                label = range[i - 1].second - range[i - 1].first + 1 + idx / 2;
            } else {
                idx = range[i].first - idx - 1;
                label = range[i - 1].second - idx / 2;
            }
        }
        res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution s;
    const auto& r = s.pathInZigZagTree(26);
    for(int i : r) cout<<i<<" ";
    cout<<endl;
}
