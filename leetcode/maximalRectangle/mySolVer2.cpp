#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == '1') matrix[i][j] = i > 0 ? matrix[i - 1][j] + 1 : 1;
                else matrix[i][j] = 0;
            }
        }

        int maxSize = 0;
        for(int i = m - 1; i >= 0; --i)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                if(matrix[i][j])
                {
                    int t = matrix[i][j];
                    int k = j;
                    while(k >= 0 && matrix[i][k])
                    {
                        t = min(t, (int)matrix[i][k]);
                        if(k < j)
                            maxSize = max(maxSize, (j - k + 1) * t);
                        --k;
                    }
                }
            }
        }

        return maxSize;
    }
};

int main() {
}
