#include "header.h"

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int rounds = 0, n = num_people;
        while(true) {
            int t = rounds * n * n + (1 + n) * n / 2;
            if(candies >= t) candies -= t;
            else break;
            ++rounds;
        }
        --rounds;
        vector<int> res(n, 0);
        for(int i = 0; i < n; ++i) {
            res[i] = (i + 1) * (rounds + 1) + n * (1 + rounds) * rounds / 2;
        }
        for(int i = 0; i < n && candies; ++i) {
            if(candies > n * (rounds + 1) + i + 1) {
                res[i] += n * (rounds + 1) + i + 1;
                candies -= n * (rounds + 1) + i + 1;
            } else {
                res[i] += candies;
                candies = 0;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
