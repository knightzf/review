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
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx > ty)
        {
            int n = tx / ty;
            tx -= n * ty;
            while(tx < sx) tx += ty;
        }
        else
        {
            int n = ty / tx;
            ty -= n * tx;
            while(ty < sy) ty += tx;
        }

        while(tx >= sx && ty >= sy)
        {
            if(tx == sx && ty == sy) return true;

            if(tx > ty)
            {
                tx = tx - ty;
            }
            else
            {
                ty = ty - tx;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    std::cout<<s.reachingPoints(1, 1, 4, 17)<<std::endl;
    std::cout<<s.reachingPoints(9, 5, 12, 8)<<std::endl;
    std::cout<<s.reachingPoints(1, 1, 2, 2)<<std::endl;
    std::cout<<s.reachingPoints(6, 3, 6, 15)<<std::endl;
    std::cout<<s.reachingPoints(5, 11, 177, 193)<<std::endl;
    std::cout<<s.reachingPoints(35, 13, 455955547, 420098884)<<std::endl;
    std::cout<<s.reachingPoints(1, 2, 999999999, 2)<<std::endl;
    std::cout<<s.reachingPoints(9, 10, 9, 19)<<std::endl;
}
