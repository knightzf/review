#include "header.h"

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> cntMap;
        for(int i : barcodes) ++cntMap[i];
        multimap<int, int, greater<int>> m;
        for(const auto& p : cntMap) {
            m.emplace(p.second, p.first);
        }
        int n = barcodes.size();
        vector<int> res; res.reserve(n);
        for(int i = 0, cnt = m.begin()->first; i < cnt; ++i)
        {
            for(auto iter = m.begin(); iter != m.end();) {
                if(!res.empty() && res.back() == iter->second) {
                    for(int j = 0; j < res.size(); ++j) {
                        int pre = j - 1;
                        if((pre == -1 || res[pre] != iter->second) && res[i] != iter->second) {
                            res.insert(res.begin() + j, iter->second);
                            break;
                        }
                    }
                }
                else res.push_back(iter->second);
                if(i == iter->first - 1) {
                    iter = m.erase(iter);
                } else {
                    ++iter;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{1,1,1,2,2,2};
    s.rearrangeBarcodes(a);
}
