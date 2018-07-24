#include "header.h"

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;
        int m = flowerbed.size();
        for(int i = 0; i < m; ++i)
        {
            if(flowerbed[i] == 0)
            {
                int prev = i - 1;
                int next = i + 1;
                if(isEmpty(flowerbed, m, prev) && isEmpty(flowerbed, m, next))
                {
                    flowerbed[i] = 1;
                    --n;
                }

                if(n == 0) return true;
            }
        }

        return false;
    }

    bool isEmpty(vector<int>& flowerbed, int m, int idx)
    {
        if(idx == -1 || idx == m) return true;
        return flowerbed[idx] == 0;
    }
};

int main() {
    //Solution s;
}
