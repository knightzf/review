#include "header.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        unordered_set<int> t;
        int res = 0;
        for(int i : nums) {
            if(t.count(i)) continue;
            t.insert(i);
            int start = i, end = i, len = 1;
            if(m.count(i - 1)) {
                start = i - 1 - abs(m[i - 1]) + 1;
                len += abs(m[i - 1]);
            }
            if(m.count(i + 1)) {
                end = i + 1 + abs(m[i + 1]) - 1;
                len += abs(m[i + 1]);
            }
            m[start] = len;
            if(len > 1) {
                m[end] = -len;
            }
            res = max(res, len);
        }
        //for(auto& p : m) cout<<p.first<<" "<<p.second<<endl;
        return res;
    }
};

int main()
{
    Solution s;
    
}