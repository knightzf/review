#include "header.h"

class RLEIterator {
private:
    int idx;
    int len;
    vector<int> v;
public:
    RLEIterator(vector<int> A) {
        idx = 0;
        len = A.size();
        v = A;
    }
    
    int next(int n) {
        while(idx < len)
        {
            if(v[idx] > n)
            {
                v[idx] -= n;
                return v[idx + 1];
            }
            else if(v[idx] == n)
            {
                idx += 2;
                return v[idx - 1];
            }
            else
            {
                n -= v[idx];
                idx += 2;
            }
        }

        return -1;
    }
};


int main()
{
    //Solution s;
}
