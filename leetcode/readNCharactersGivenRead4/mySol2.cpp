#include "header.h"

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) {
        int res = 0;
        while(res < n) {
            int t = read4(buf);
            buf += t;
            res += t;
            if(res > n) res = n;
            if(!t) break;
        }
        return res;
    }
};


int main()
{
    //Solution s;    
}