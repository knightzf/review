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
        if(x > y) std::swap(x, y);
        if(z > y) return false;

        vector<vector<bool>> visited(x + 1, vector<bool>(y + 1, false));
        visited[0][0] = true;
        return bfs(0, 0, x, y, z, visited);
    }

    bool bfs(int i, int j, int x, int y, int z, vector<vector<bool>>& visited)
    {
        std::cout<<i<<" "<<j<<std::endl;
        if(i == z || j == z) return true;

        if(i < x && !visited[x][j]){
            visited[x][j] = true;
            if(bfs(x, j, x, y, z, visited)) return true;
            visited[x][j] = false;
        }

        if(j < y && !visited[i][y]){
            visited[i][y] = true;
            if(bfs(i, y, x, y, z, visited)) return true;
            visited[i][y] = false;
        }

        if(i > 0 && !visited[0][j]){
            visited[0][j] = true;
            if(bfs(0, j, x, y, z, visited)) return true;
            visited[0][j] = false;
        }

        if(j > 0 && !visited[i][0]){
            visited[i][0] = true;
            if(bfs(i, 0, x, y, z, visited)) return true;
            visited[i][0] = false;
        }

        if(i > 0 && j < y){
            if(i >= y - j && !visited[i - y + j][y]){
                visited[i - y + j][y] = true;
                if(bfs(i - y + j, y, x, y, z, visited)) return true;
                visited[i - y + j][y] = false;
            }
            else if(i < y - j && !visited[0][i + j]){
                visited[0][i + j] = true;
                if(bfs(0, i + j, x, y, z, visited)) return true;
                visited[0][i + j] = false;
            }
        }

        if(j > 0 && i < x){
            if(j >= x - i && !visited[x][j - x + i]){
                visited[x][j - x + i] = true;
                if(bfs(x, j - x + i, x, y, z, visited)) return true;
                visited[x][j - x + i] = false;
            }
            else if(j < x - i && !visited[i + j][0]){
                visited[i + j][0] = true;
                if(bfs(i + j, 0, x, y, z, visited)) return true;
                visited[i + j][0] = false;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    //std::cout<<s.canMeasureWater(3, 5, 4)<<std::endl;
    //std::cout<<s.canMeasureWater(2, 6, 5)<<std::endl;
    std::cout<<s.canMeasureWater(22003, 31237, 1)<<std::endl;
}
