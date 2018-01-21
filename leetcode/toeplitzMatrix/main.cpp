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
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int num = matrix[i][j];
                if(i + 1 < m && j + 1 < n)
                {
                    if(num != matrix[i + 1][j + 1]) return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution s;
}
