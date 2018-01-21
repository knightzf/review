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

        int start = 0;
        std::unordered_set<int> s;
        int result = 0;
        for(int i = 0; i < n; ++i)
        {
            s.insert(arr[i]);
            bool good = true;
            for(int j = start; j <= i; ++j)
            {
                if(s.find(j) == s.end())
                {
                    good = false;
                    break;
                }
            }

            if(good)
            {
                ++result;
                start = i + 1;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> a{4, 3, 2, 1, 0};
    vector<int> b{1, 0, 2, 3, 4};
    std::cout<<s.maxChunksToSorted(a)<<std::endl;
    std::cout<<s.maxChunksToSorted(b)<<std::endl;
}
