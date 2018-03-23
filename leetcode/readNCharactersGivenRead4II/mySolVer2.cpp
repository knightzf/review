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

int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int totalCnt = 0;
        if(sz)
        {
            totalCnt += min(n, sz);
            memcpy(buf, buffer, min(n, sz) * sizeof(char));
            if(n >= sz)
            {
                n -= sz;
                sz = 0;
            }
            else
            {
                memcpy(buffer, buffer + n, (sz - n) * sizeof(char));
                sz -= n;
                n = 0;
            }
        }

        while(n)
        {
            int cnt = read4(buffer);
            if(n >= cnt)
            {
                totalCnt += cnt;
                n -= cnt;
                memcpy(buf, buffer, cnt * sizeof(char));
            }
            else
            {
                totalCnt += n;
                memcpy(buf, buffer, n * sizeof(char));
                memcpy(buffer, buffer + n, (cnt - n) * sizeof(char));
                sz = cnt - n;
                n = 0;
            }
            if(cnt < 4) break;
        }
        return totalCnt;
    }
private:
    char buffer[4];
    int sz = 0;
};

int main() {
}
