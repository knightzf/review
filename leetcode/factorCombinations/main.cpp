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
    vector<vector<int>> getFactors(int n) {
        return impl(n, 2);
    }

    vector<vector<int>> impl(int n, int start)
    {
        vector<vector<int>> res;
        for(int i = start; i <= sqrt(n); ++i)
        {
            if(n % i == 0)
            {
                int remain = n / i;
                res.push_back({i, remain});

                const auto& r = impl(remain, i);
                for(const auto& v : r)
                {
                    vector<int> t{i};
                    t.insert(t.end(), v.begin(), v.end());
                    res.emplace_back(t);
                }
            }
        }

        return res;
    }
};


int main() {
    Solution s;
    const auto& r = s.getFactors(32);
    for(const auto& i : r)
    {
        for(auto j : i)
        {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
}
