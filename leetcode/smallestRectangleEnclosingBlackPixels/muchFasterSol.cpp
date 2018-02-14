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

        for(int i = 0; i < m; ++i)
        {
            bool found = false;
            for(int j = 0; j < n; ++j)
            {
                if(image[i][j] == '1')
                {
                    minX = i;
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        for(int i = m - 1; i >= 0; --i)
        {
            bool found = false;
            for(int j = 0; j < n; ++j)
            {
                if(image[i][j] == '1')
                {
                    maxX = i;
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        for(int j = 0; j < n; ++j)
        {
            bool found = false;
            for(int i = 0; i < m; ++i)
            {
                if(image[i][j] == '1')
                {
                    minY = j;
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        for(int j = n - 1; j >= 0; --j)
        {
            bool found = false;
            for(int i = 0; i < m; ++i)
            {
                if(image[i][j] == '1')
                {
                    maxY = j;
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        return (maxX - minX + 1) * (maxY - minY + 1);
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
