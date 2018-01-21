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
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;

        vector<int> sorted = arr;
        std::sort(sorted.begin(), sorted.end());

        std::unordered_map<int, int> s;
        int result = 0;
        std::unordered_map<int, int> temp;
        for(int i = 0; i < n; ++i)
        {
            ++s[sorted[i]];

            ++temp[arr[i]];

            for(const auto& p : temp)
            {
                if(p.second > 0)
                {
                    for(int j = 0; j < p.second; ++j)
                    {
                        if(s.find(p.first) != s.end())
                        {
                            --s[p.first];
                            if(s[p.first] == 0) s.erase(p.first);
                            --temp[p.first];
                        }
                    }
                }
            }

            if(s.empty()) ++result;
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> a{4, 3, 2, 1, 0};
    vector<int> b{1, 0, 2, 3, 4};
    vector<int> c{2,1,3,4,4};
    std::cout<<s.maxChunksToSorted(a)<<std::endl;
    std::cout<<s.maxChunksToSorted(b)<<std::endl;
    std::cout<<s.maxChunksToSorted(c)<<std::endl;
}
