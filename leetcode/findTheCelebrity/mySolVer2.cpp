#include "header.h"

bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        for(int i = 0; i < n; ++i)
        {
            int j = 0;
            for(; j < n; ++j)
            {
                if(j != i && !knows(j, i))
                {
                    break;
                }
            }
            if(j != n) continue;

            j = 0;
            for(; j < n; ++j)
            {
                if(j != i && knows(i, j))
                    break;
            }

            if(j == n) return i;
        }
        return -1;
    }
};

int main()
{
    Solution s;
}
