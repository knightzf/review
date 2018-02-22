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

        vector<int> res(k, 0);
        for(int i = max(0, k - n); i <= k && i <= m; ++i)
        {
            std::cout<<i<<" "<<k-i<<std::endl;
            const vector<int>& r = merge(maxArray(nums1, i, m), maxArray(nums2, k - i, n), k);
            if(r > res)
            {
                res = r;
            }
        }

        return res;
    }

    vector<int> merge(const vector<int>& a, const vector<int>& b, int k)
    {
        vector<int> res; res.reserve(k);
        int m = a.size(), n = b.size();
        int i = 0, j = 0;

        while(k > 0)
        {
            if(i < m && j < n)
            {
                if(a[i] == b[j])
                {
                    int ii = i, jj = j;
                    while(a[ii] == b[jj] && ii < m && jj < n)
                    {
                        ++ii; ++jj;
                    }

                    res.push_back((jj == n || (ii < m && a[ii] > b[jj])) ? a[i++] : b[j++]);
                }
                else
                {
                    res.push_back(a[i] > b[j] ? a[i++] : b[j++]);
                }
            }
            else if(i == m)
                res.push_back(b[j++]);
            else
                res.push_back(a[i++]);
            --k;
        }
        return res;
    }

    vector<int> maxArray(const vector<int>& nums, int k, int n)
    {
        vector<int> res(k);
        for (int i = 0, j = 0; i < n; ++i)
        {
            while (n - i + j > k && j > 0 && res[j - 1] < nums[i]) j--;
            if (j < k) res[j++] = nums[i];
        }
        return res;
    }
};

int main() {
    Solution s;
    //vector<int> a{3, 4, 6, 5};
    //vector<int> b{9, 1, 2, 5, 8, 3};
    vector<int> a{2,5,6,4,4,0};
    vector<int> b{7,3,8,0,6,5,7,6,2};
    const auto& r = s.maxNumber(a, b, 15);
    for(int i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
