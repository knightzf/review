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
        std::queue<std::pair<int, int>> q;
        q.push(std::make_pair(sx, sy));
        int qsize = q.size();

        while(!q.empty())
        {
            for(int i = 0; i < qsize; ++i)
            {
                const auto& p = q.front();
                if(p.first == tx && p.second == ty)
                {
                    return true;
                }

                if(p.first + p.second <= tx || p.first + p.second + p.second <= ty)
                    q.push(std::make_pair(p.first + p.second, p.second));
                if(p.first + p.first + p.second <= tx || p.first + p.second <= ty)
                    q.push(std::make_pair(p.first, p.first + p.second));

                q.pop();
            }

            qsize = q.size();
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
}
