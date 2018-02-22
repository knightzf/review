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

        return impl(nums1, nums2, m, n, k, 0, 0);
    }

    vector<int> impl(vector<int>& nums1, vector<int>& nums2, int m, int n, int k,
                     int iStart, int jStart)
    {
        vector<int> res;
        while(k > 0)
        {
            int maxDigit1 = INT_MIN, maxDigit2 = INT_MIN;
            int maxNumIdx1 = -1, maxNumIdx2 = -1;

            for(int j = jStart; j < n; ++j)
            {
                if(n - j - 1 + m - iStart >= k - 1)
                {
                    if(nums2[j] > maxDigit2)
                    {
                        maxDigit2 = nums2[j];
                        maxNumIdx2 = j;
                    }
                }
                else break;
            }

            for(int i = iStart; i < m; ++i)
            {
                if(m - i  - 1 + n - jStart >= k - 1)
                {
                    if(nums1[i] > maxDigit1)
                    {
                        maxDigit1 = nums1[i];
                        maxNumIdx1 = i;
                    }
                }
                else break;
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
                const auto& r1 = impl(nums1, nums2, m, n, k - 1, maxNumIdx1 + 1,jStart);
                const auto& r2 = impl(nums1, nums2, m, n, k - 1, iStart, maxNumIdx2 + 1);
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
