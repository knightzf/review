#include "header.h"

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        int m = nums1.size(), n = nums2.size();
        if(m * n == 0) return res;
        pair<int, int> p1{0, 0};
        pair<int, int> p2{0, 1};

        auto isValid = [&](pair<int, int>& p, bool p1 = true){
            if(p1) return p.first < m  && p.second < n;
            return p.first < n && p.second < m;
        };

        auto advance = [&](pair<int, int>& p, bool p1 = true){
            if(p1){
                if(p.second < n - 1) ++p.second;
                else {
                    ++p.first;
                    p.second  = p.first;
                }
            }
            else{
                if(p.second < m - 1) ++p.second;
                else {
                    ++p.first;
                    p.second = p.first + 1;
                }
            }
        };

        while(res.size() < k)
        {
            if(isValid(p1) && isValid(p2, false))
            {
                if(nums1[p1.first] + nums2[p1.second] <= nums1[p2.second] + nums2[p2.first])
                {
                    res.emplace_back(nums1[p1.first], nums2[p1.second]);
                    advance(p1);
                }
                else
                {
                    res.emplace_back(nums1[p2.second], nums2[p2.first]);
                    advance(p2, false);
                }
            }
            else if(isValid(p1))
            {
                res.emplace_back(nums1[p1.first], nums2[p1.second]);
                advance(p1);
            }
            else if(isValid(p2, false))
            {
                res.emplace_back(nums1[p2.second], nums2[p2.first]);
                advance(p2, false);
            }
            else
                break;
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 1, 2};
    vector<int> b{1, 2, 3};
    const auto& r = s.kSmallestPairs(a, b, 2);
    for(const auto& i : r)
    {
        std::cout<<i.first<<" "<<i.second<<" |";
    }
    std::cout<<std::endl;
}
