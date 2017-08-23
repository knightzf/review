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

using namespace std;

class Solution {
public:

    int strangePrinter(string s)
    {
        size_t n = s.size();

        std::vector<std::vector<int>> result(n, std::vector<int>(n, -1));

        for(size_t i = 0; i < n; ++i)
        {
            result[i][i] = 1;
        }

        for(size_t i = 0; i < n -1; ++i)
        {
            result[i][i + 1] = s[i] == s[i + 1] ? 1 : 2;
        }

        for(size_t len = 2; len < n; ++len)
        {
            for(size_t start = 0; start + len < n; ++start)
            {
                result[start][start + len] = len + 1;
                for(size_t k = 0; k < len; ++k)
                {
                    int temp = result[start][start + k] +
                        result[start + k + 1][start + len];
                    result[start][start + len] = std::min(result[start][start + len],
                                                          s[start + k] == s[start + len] ? temp - 1 : temp);
                }
            }
        }

        return result[0][n - 1];
    }

};

int main()
{
    Solution sol;
    string s = "bdbcdc";
    std::cout<<sol.strangePrinter(s)<<std::endl;
    return 0;
}
