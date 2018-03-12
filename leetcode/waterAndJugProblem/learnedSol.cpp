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
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z) return false;
        if(z % gcd(x, y) == 0) return true;
        return false;
    }

    int gcd(int x, int y)
    {
        if(x < y) std::swap(x, y);
        if(y == 0) return x;

        int remain = x % y;
        return (y, remain);
    }
};

int main() {
    Solution s;
    std::cout<<s.canMeasureWater(3, 5, 4)<<std::endl;
    //std::cout<<s.canMeasureWater(2, 6, 5)<<std::endl;
    std::cout<<s.canMeasureWater(22003, 31237, 1)<<std::endl;
}
