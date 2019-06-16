#include "header.h"

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a = 0;
        for(int i : nums) a ^= i;
        int b = (a & -a);
        int c = 0, d = 0;
        for(int i : nums) {
            if(b & i) c ^= i;
            else d ^= i;
        }
        return {c, d};
    }
};

int main()
{
    //Solution s;
}