#include "header.h"

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        unordered_map<int, vector<pair<int, int>>> m;
        stack<int> s;
        int depth = 0;
        for(int i = 0, n = seq.size(); i < n; ++i) {
            char c = seq[i];
            if(c == '(') {
                s.push(i);
                depth = max(depth, (int)s.size());
            }
            else {
                m[s.size()].emplace_back(make_pair(s.top(), i));
                s.pop();
            }
        }
        vector<int> res(seq.size(), 0);
        if(depth > 1) {
            int d = depth / 2 + 1;
            for(const auto& p : m[d]) {
                for(int i = p.first; i <= p.second; ++i) res[i] = 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    const auto& r = s.maxDepthAfterSplit("(()())");
    for(int i : r) cout<<i<<" "; cout<<endl;
}
