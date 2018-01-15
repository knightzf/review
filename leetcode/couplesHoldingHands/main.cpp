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
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();

        std::unordered_map<int, int> numIdxMap;
        for(int i = 0; i < n; ++i)
        {
            numIdxMap[row[i]] = i;
        }

        int moves = 0;

        for(int i = 0; i < n; i += 2)
        {
            int num = row[i];
            int gf = num % 2 == 0 ? num + 1 : num - 1;
            int gfIdx = numIdxMap[gf];

            if(gfIdx != i + 1)
            {
                ++moves;
                numIdxMap[gf] = i + 1;
                numIdxMap[row[i + 1]] = gfIdx;
                std::swap(row[gfIdx], row[i + 1]);
            }
        }

        return moves;
    }
};


int main() {
    Solution s;
    vector<int> a{0, 2, 1, 3};
    std::cout<<s.minSwapsCouples(a)<<std::endl;
}
