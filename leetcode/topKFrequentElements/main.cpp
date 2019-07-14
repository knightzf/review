#include "header.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(int num : nums) ++cnt[num];
        unordered_map<int, vector<int>> m;
        int maxCnt = 0;
        for(const auto& p : cnt) {
            maxCnt = max(maxCnt, p.second);
            m[p.second].push_back(p.first);
        }
        vector<int> res;
        for(int i = maxCnt; i > 0; --i) {
            if(m.count(i)) {
                for(int num : m[i]) {
                    if (res.size() < k) res.emplace_back(num);
                    else return res;
                }
            }
        }
        return res;
    }
};

int main()
{
    //Solution s;
}