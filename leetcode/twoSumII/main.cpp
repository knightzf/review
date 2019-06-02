#include "header.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while(i < j) {
            while(j > i && numbers[i] + numbers[j] > target) --j;
            if(j > i && numbers[i] + numbers[j] == target)
                return {i + 1, j + 1};
            ++i;
        }
        return {-1, -1};
    }
};

int main()
{
    Solution s;
}