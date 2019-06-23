#include "header.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, h = citations.size(), n = h;
        while(l < h) {
            int m = (l + h) / 2;
            if(citations[m] >= n - m) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        return n - h;
    }
};

int main()
{
    //Solution s;
}