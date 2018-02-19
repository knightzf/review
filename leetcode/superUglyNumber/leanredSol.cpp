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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> nums(n, 1);
        vector<int> idx(primes.size());

        for(int i = 1; i < n; ++i)
        {
            nums[i] = INT_MAX;
            for(int j = 0; j < primes.size(); ++j)
            {
                nums[i] = std::min(nums[i], primes[j] * nums[idx[j]]);
            }

            for(int j = 0; j < primes.size(); ++j)
            {
                while(primes[j] * nums[idx[j]] <= nums[i]) ++idx[j];
            }

            for(int i = 0; i < n; ++i)
            {
                std::cout<<nums[i]<<" ";
            }
            std::cout<<std::endl;

            for(int i = 0; i < primes.size(); ++i)
            {
                std::cout<<idx[i]<<" ";
            }
            std::cout<<std::endl;
            std::cout<<"---"<<std::endl;
        }

        return nums[n - 1];
    }
};

int main() {
    Solution s;
    vector<int> a{2, 7, 13, 19};
    std::cout<<s.nthSuperUglyNumber(12, a)<<std::endl;
}
