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
    int preimageSizeFZF(int K) {
        static std::map<int, int> m{{1, 5}};
        if(K == 0) return 5;
        while(m.rbegin()->first < K)
        {
            int t = m.rbegin()->second + 5;
            int c = 0;
            while(t % 10 == 0)
            {
                ++c;
                t = t / 10;
            }
            while(t % 5 == 0)
            {
                ++c;
                t = t / 5;
            }
            m.emplace(m.rbegin()->first + c, m.rbegin()->second + 5);
        }

        auto iter = m.find(K);
        return iter == m.end() ? 0 : 5;
    }
};


int main() {
    Solution s;
    std::cout<<s.preimageSizeFZF(5)<<std::endl;
    std::cout<<s.preimageSizeFZF(80502705)<<std::endl;
}
