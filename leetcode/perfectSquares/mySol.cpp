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
    int numSquares(int n) {
        static std::unordered_map<int, int> m;
        if(m.find(n) != m.end()) return m[n];

        int root = std::sqrt(n);
        if(root * root == n) return 1;
        int minCnt = INT_MAX;
        for(int i = root; i > 0; --i)
        {
            int r = numSquares(n - i * i);
            if(r != -1)
            {
                if(r < minCnt) minCnt = r;
                //else break;
            }
        }

        minCnt = minCnt == INT_MAX ? -1 : minCnt + 1;
        m[n] = minCnt;

        return minCnt;
    }
};

int main() {
    Solution s;
    std::cout<<s.numSquares(12)<<std::endl;
    std::cout<<s.numSquares(61)<<std::endl;
}
