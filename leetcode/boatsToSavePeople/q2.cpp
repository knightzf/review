#include "header.h"

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int res = 0;
        int n = people.size(), i = 0, j = n - 1;
        while(j > i)
        {
            if(people[i] + people[j] <= limit)
            {
                ++i;
            }
            --j;
            ++res;
        }
        if(j == i) ++res;
        return res;
    }
};

int main()
{
    Solution s;
}
