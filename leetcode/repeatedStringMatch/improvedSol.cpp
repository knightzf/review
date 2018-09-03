#include "header.h"

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int m = A.size(), n = B.size();

        for(int i = 0; i < m; ++i)
        {
            if(A[i] == B[0])
            {
                int k = i;
                bool good = true;
                for(int j = 0; j < n; ++j, ++k)
                {
                    if(A[k % m] != B[j]) {
                        good = false;
                        break;
                    }
                }

                if(good) {
                    return k % m == 0 ? (k / m) : (k / m + 1);
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
}
