#include "header.h"

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    char m_buf[1000];
    int m_total = 0;
    int m_consumed = 0;
public:
    int read(char *buf, int n) {
        int res = 0;
        int require = m_consumed + n;
        while(m_total < require) {
            int t = read4(m_buf + m_total);
            m_total += t;
            res += t;
            if(!t) break;
        }
        memcpy(buf, m_buf + m_consumed, res);
        m_consumed += res;
        return res;
    }
};


int main()
{
    //Solution s;    
}