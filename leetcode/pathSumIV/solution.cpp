#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>

using namespace std;


class Solution {
public:
    int pathSum(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }

        int sum = 0;

        auto baseIdx = [] (int depth) {
            return int(std::pow(2, depth - 1)) - 1;
        };

        auto parentIdx = [] (int idx) {
            return (idx - 1) / 2;
        };

        std::vector<std::pair<int, bool>> values(15, {-1, false});
        for(size_t i = 0; i < nums.size(); ++i)
        {
            int depth = nums[i] / 100;
            int position = nums[i] % 100 / 10;
            int value = nums[i] % 10;

            int idx = baseIdx(depth) + position - 1;
            values[idx].first = value;
            if(idx != 0) values[parentIdx(idx)].second = true;
        }

//        for(auto& i : values)
//        {
//            std::cout<<i.first<<" "<<i.second<<std::endl;
//        }

        for(int i = values.size() - 1; i >= 0; --i)
        {
            if(values[i].first != -1 && values[i].second == false)
            {
                sum += values[i].first;

                if(i != 0)
                {
                    int pIdx = parentIdx(i);
                    while(true)
                    {
                        sum += values[pIdx].first;
                        if(pIdx == 0)
                            break;
                        pIdx = parentIdx(pIdx);
                    }
                }
            }
        }

        return sum;

    }
};

int main()
{
    Solution sol;
    //std::vector<int> a{3, 4, 2, 3};
    std::vector<int> a{111,217,221,315,415};
    std::cout<<sol.pathSum(a)<<std::endl;
    //std::cout<<sol.generateParenthesis(3)<<std::endl;
    return 0;
}
