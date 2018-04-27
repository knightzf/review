#include "header.h"

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, int> idxMap;
        for(int i = 0; i < n; ++i)
            idxMap[stones[i]] = i;
        vector<unordered_set<int>> speedV(n);
        speedV[0].insert(1);
        for(int i = 0; i < n; ++i)
        {
            if(i == n - 1) return !speedV[i].empty();
            for(int s : speedV[i])
            {
                if(idxMap.find(stones[i] + s) != idxMap.end())
                {
                    auto& p = speedV[idxMap[stones[i] + s]];
                    if(s > 1) p.insert(s - 1);
                    p.insert(s);
                    p.insert(s + 1);
                }
            }
        }
    }
};

int main()
{
    Solution s;
    //vector<int> a{0, 1, 3, 5, 6, 8, 12, 17};
    vector<int> a{0,1,2,3,4,8,9,11};
    std::cout<<s.canCross(a)<<std::endl;
}
