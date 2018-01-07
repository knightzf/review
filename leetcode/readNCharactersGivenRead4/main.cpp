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

using namespace std;

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int count = 0;
        while(count < n)
        {
            char temp[4];
            int c = read4(temp);

            if(c == 0) break;

            if(count + c < n)
            {
                count += c;
                memcpy(buf, temp, c);
                buf += c;
                continue;
            }
            else if(count + c == n)
            {
                count += c;
                memcpy(buf, temp, c);
                buf += c;
                break;
            }
            else
            {
                memcpy(buf, temp, n - count);
                buf += n - count;
                count = n;
                break;
            }
        }

        return count;
    }
};

int main()
{
    Solution s;
}
