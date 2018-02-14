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
private:
    int minX, minY, maxX, maxY;
    int m, n;
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        m = image.size();
        if(m == 0) return 0;
        n = image[0].size();
        if(n == 0) return 0;

        minX = x; minY = y;
        maxX = x; maxY = y;

        std::set<std::pair<int, int>> visited;
        visited.emplace(x, y);

        visit(image, x, y, visited);

        //std::cout<<maxX<<" "<<minX<<std::endl;
        //std::cout<<maxY<<" "<<minY<<std::endl;
        return (maxX - minX + 1) * (maxY - minY + 1);
    }

    void visit(vector<vector<char>>& image,
               int x, int y, std::set<std::pair<int, int>>& visited)
    {
        //std::cout<<x<<" "<<y<<std::endl;
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
        if(x > 0 && image[x - 1][y] == '1' && visited.find(std::make_pair(x - 1, y)) == visited.end())
        {
            visited.emplace(x - 1, y);
            visit(image, x - 1, y, visited);
        }

        if(y > 0 && image[x][y - 1] == '1' && visited.find(std::make_pair(x, y - 1)) == visited.end())
        {
            visited.emplace(x, y - 1);
            visit(image, x, y - 1, visited);
        }

        if(x < m - 1 && image[x + 1][y] == '1' && visited.find(std::make_pair(x + 1, y)) == visited.end())
        {
            visited.emplace(x + 1, y);
            visit(image, x + 1, y, visited);
        }

        if(y < n - 1 && image[x][y + 1] == '1' && visited.find(std::make_pair(x, y + 1)) == visited.end())
        {
            visited.emplace(x, y + 1);
            visit(image, x, y + 1, visited);
        }
    }
};

int main() {
    Solution s;
    vector<vector<char>> a{{'1','1','1','1','1','1','1','1','0','1'},
 {'1','0','0','0','0','0','0','1','0','1'},
 {'1','0','1','1','1','1','0','1','0','1'},
 {'1','0','1','0','0','1','0','1','0','1'},
 {'1','0','1','0','1','1','0','1','0','1'},
 {'1','0','1','0','0','0','0','1','0','1'},
 {'1','0','1','1','1','1','1','1','0','1'},
 {'1','0','0','0','0','0','0','0','0','1'},
 {'1','1','1','1','1','1','1','1','1','1'}};
 std::cout<<s.minArea(a, 4, 4)<<std::endl;
}
