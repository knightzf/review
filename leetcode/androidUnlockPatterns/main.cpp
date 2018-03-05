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
    int numberOfPatterns(int m, int n) {
        int res = 0;
        vector<bool> visited(10, false);
        impl(m, n, 0, 0, visited, res);
        return res;
    }

private:
    void impl(int m, int n, int pre, int depth, vector<bool>& visited, int& res)
    {
        if(depth >= m && depth <= n) ++res;
        if(depth > n) return;

        for(int i = 1; i <= 9; ++i)
        {
            if(canReach(pre, i, visited))
            {
                visited[i] = true;
                impl(m, n, i, depth + 1, visited, res);
                visited[i] = false;
            }
        }
    }

    bool canReach(int i, int j, vector<bool>& visited)
    {
        if(i == 0) return true;
        if(visited[j]) return false;

        if(std::abs(i - j) == 6) return visited[(i + j)/2] == true;

        int a = std::min(i, j);
        int b = std::max(i, j);
        if((a == 1 && b == 9) || (a == 3 && b == 7) || (a == 1 && b == 3)
           || (a == 4 && b == 6) || (a == 7 && b == 9) ) return visited[(i + j)/2] == true;

        return true;
    }
};


int main() {
    Solution s;
    std::cout<<s.numberOfPatterns(1, 1)<<std::endl;
    std::cout<<s.numberOfPatterns(1, 2)<<std::endl;
}
