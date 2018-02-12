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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        vector<int> tail(n, 0);
        int sz = 0;
        for(auto num : nums)
        {
            int i = 0, j = sz;
            while(i != j)
            {
                int m = (i + j) / 2;
                if(tail[m] < num)
                {
                    i = m + 1;
                }
                else
                {
                    j = m;
                }
            }

            tail[i] = num;
            if(i == sz) ++sz;
        }

        return sz;
    }
};

int main() {
    Solution s;
    //vector<int> a{10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> a{1, 3, 6, 7, 9, 4, 10, 5, 6};
    std::cout<<s.lengthOfLIS(a)<<std::endl;
}
