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
    int nthUglyNumber(int n) {
        static vector<int> v{1};
        static int idx2 = 0;
        static int idx3 = 0;
        static int idx5 = 0;

        while(n > v.size())
        {
            int newNum = min(v[idx2] * 2, min(v[idx3] * 3, v[idx5] * 5));
            if(newNum == v[idx2] * 2) ++idx2;
            if(newNum == v[idx3] * 3) ++idx3;
            if(newNum == v[idx5] * 5) ++idx5;
            v.push_back(newNum);
        }

        for(auto i : v)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;

        return v[n - 1];
    }
};

int main() {
    Solution s;
    std::cout<<s.nthUglyNumber(10)<<std::endl;
}
