#include "header.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int firstZeroIdx = INT_MAX, firstOneIdx = INT_MAX, firstTwoIdx = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            switch(nums[i])
            {
            case 0:
                {
                    int actualIdx = i;
                    if(firstOneIdx < i && firstTwoIdx < i)
                    {
                        swap(nums[firstOneIdx], nums[firstTwoIdx]);
                        swap(nums[i], nums[firstOneIdx]);
                        actualIdx = firstOneIdx;
                        ++firstOneIdx;
                        ++firstTwoIdx;
                    }
                    else if(firstOneIdx < i)
                    {
                        swap(nums[i], nums[firstOneIdx]);
                        actualIdx = firstOneIdx;
                        ++firstOneIdx;
                    }
                    else if(firstTwoIdx < i)
                    {
                        swap(nums[i], nums[firstTwoIdx]);
                        actualIdx = firstTwoIdx;
                        ++firstTwoIdx;
                    }

                    if(firstZeroIdx == INT_MAX) firstZeroIdx = actualIdx;
                    break;
                }
            case 1:
                {
                    int actualIdx = i;
                    if(firstTwoIdx < i)
                    {
                        swap(nums[i], nums[firstTwoIdx]);
                        actualIdx = firstTwoIdx;
                        ++firstTwoIdx;
                    }

                    if(firstOneIdx == INT_MAX) firstOneIdx = actualIdx;
                    break;
                }
            case 2:
                {
                    if(firstTwoIdx == INT_MAX) firstTwoIdx = i;
                    break;
                }
            default:
                break;
            }
        }
    }
};

int main()
{
    Solution s;
    //vector<int> a{1, 1, 2, 2, 0, 0, 1};
    vector<int> a{2, 2, 2, 1, 0, 0, 1};
    s.sortColors(a);
    for(auto i : a)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
