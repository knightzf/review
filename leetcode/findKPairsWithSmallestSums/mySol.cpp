#include "header.h"

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        int m = nums1.size(), n = nums2.size();
        if(m * n == 0) return res;

        map<int, set<pair<int, int>>> mm;
        mm[nums1[0] + nums2[0]].emplace(0, 0);

        while(!mm.empty() && res.size() < k)
        {
            auto& t = mm.begin()->second;
            auto p = *t.begin();
            res.emplace_back(nums1[p.first], nums2[p.second]);
            if(t.size() == 1) mm.erase(mm.begin());
            else t.erase(t.begin());

            if(p.first + 1 < m)
                mm[nums1[p.first + 1] + nums2[p.second]].emplace(p.first + 1, p.second);
            if(p.second + 1 < n)
                mm[nums1[p.first] + nums2[p.second + 1]].emplace(p.first, p.second + 1);
        }

        return res;
    }
};

int main()
{
    Solution s;
    //vector<int> a{1, 1, 2};
    //vector<int> b{1, 2, 3};
    vector<int> a{-10,-4,0,0,6};
    vector<int> b{3,5,6,7,8,100};
    const auto& r = s.kSmallestPairs(a, b, 10);
    for(const auto& i : r)
    {
        std::cout<<i.first<<" "<<i.second<<" |";
    }
    std::cout<<std::endl;
}
