#include "header.h"

bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<bool> isCele(n, true);
        for(int i = 0; i < n; ++i) {
            if(isCele[i]) {
                for(int j = 0; j < n; ++j) {
                    if(j != i) {
                        bool t = knows(j, i);
                        if(t) isCele[j] = false;
                        else {
                            isCele[i] = false;
                            break;
                        }
                    }
                }
                if(isCele[i]) {
                    for(int j = 0; j < n; ++j) {
                        if(j != i && knows(i, j)) {
                            isCele[i] = false;
                            break;
                        }
                    }
                    if(isCele[i]) return i;
                }
            }
        }
        return -1;
    }
};

int main()
{
    //Solution s;
}