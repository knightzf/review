#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        std::unordered_map<int, std::set<int>> posMap1, posMap2;
        populatePosMap(nums1, m, posMap1);
        populatePosMap(nums2, n, posMap2);

        return impl(nums1, nums2, m, n, k, 0, 0, posMap1, posMap2);
    }

    void populatePosMap(const vector<int>& nums, int n, std::unordered_map<int, std::set<int>>& posMap)
    {
        for(int i = 0; i < n; ++i)
        {
            posMap[nums[i]].insert(i);
        }
    }

    vector<int> impl(vector<int>& nums1, vector<int>& nums2, int m, int n, int k,
                     int iStart, int jStart,
                     const std::unordered_map<int, std::set<int>>& posMap1,
                     const std::unordered_map<int, std::set<int>>& posMap2)
    {
        vector<int> res;
        while(k > 0)
        {
            int maxDigit1 = INT_MIN, maxDigit2 = INT_MIN;
            int maxNumIdx1 = -1, maxNumIdx2 = -1;

            for(int i = 9; i >= 0; --i)
            {
                if(posMap1.find(i) != posMap1.end())
                {
                    auto iter = posMap1.at(i).lower_bound(iStart);
                    if(iter != posMap1.at(i).end() && *iter <= m + n - jStart - k)
                    {
                        maxDigit1 = i; maxNumIdx1 = *iter;
                        break;
                    }
                }
            }

            for(int i = 9; i >= 0; --i)
            {
                if(posMap2.find(i) != posMap2.end())
                {
                    auto iter = posMap2.at(i).lower_bound(jStart);
                    if(iter != posMap2.at(i).end() && *iter <= m + n - iStart - k)
                    {
                        maxDigit2 = i; maxNumIdx2 = *iter;
                        break;
                    }
                }
            }

            if(maxDigit1 != maxDigit2)
            {
                res.push_back(std::max(maxDigit1, maxDigit2));
                iStart = maxDigit1 > maxDigit2 ? maxNumIdx1 + 1 : iStart;
                jStart = maxDigit2 > maxDigit1 ? maxNumIdx2 + 1 : jStart;
            }
            else
            {
                res.push_back(maxDigit1);
                const auto& r1 = impl(nums1, nums2, m, n, k - 1, maxNumIdx1 + 1,jStart, posMap1, posMap2);
                const auto& r2 = impl(nums1, nums2, m, n, k - 1, iStart, maxNumIdx2 + 1, posMap1, posMap2);
                if(r1 < r2)
                {
                    res.insert(res.end(), r2.begin(), r2.end());
                }
                else
                    res.insert(res.end(), r1.begin(), r1.end());

                break;
            }

            --k;
        }

        return res;
    }
};

int main() {
    Solution s;
    //vector<int> a{3, 4, 6, 5};
    //vector<int> b{9, 1, 2, 5, 8, 3};
    vector<int> a{6, 7};
    vector<int> b{6, 0, 4};
    const auto& r = s.maxNumber(a, b, 5);
    for(int i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
