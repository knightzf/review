#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
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
    vector<vector<int>> combinationSum3(int k, int n) {
        return impl(k, n, 1);
    }

    vector<vector<int>> impl(int k, int n, int startNum)
    {
        vector<vector<int>> res;

        for(int i = startNum; i <= 9; ++i)
        {
            if(i < n)
            {
                const auto& r = impl(k - 1, n - i, i + 1);
                for(const auto& v : r)
                {
                    vector<int> t{i};
                    t.insert(t.end(), v.begin(), v.end());
                    res.emplace_back(t);
                }
            }
            else if(i == n)
            {
                if(k == 1)
                {
                    res.push_back({i});
                }
            }
            else
            {
                break;
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    const auto& a = s.combinationSum3(3, 9);
    for(const auto& i : a)
    {
        for(auto j : i)
        {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
}
