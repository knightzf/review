#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> res; res.reserve(n);

        if(a == 0)
        {
            for(int num : nums)
                res.push_back(calc(a, b, c, num));
            if(b < 0)
                std::reverse(res.begin(), res.end());
            return res;
        }

        double midPoint = - b / 2.0 / a;
        int leftCandidateIdx = -1;
        int rightCandidateIdx = n;
        if(midPoint < nums[0]) rightCandidateIdx = 0;
        else if(midPoint > nums.back()) leftCandidateIdx = n - 1;
        else
        {
            int i = 0, j = n;
            while(i != j && i + 1 != j)
            {
                int mid = (i + j) / 2;
                if(midPoint > nums[mid])
                {
                    i = mid;
                }
                else if(midPoint < nums[mid])
                {
                    j = mid;
                }
                else
                {
                    leftCandidateIdx = mid;
                    rightCandidateIdx = mid + 1;
                    break;
                }
            }

            if(i + 1 == j)
            {
                leftCandidateIdx = i;
                rightCandidateIdx = j;
            }
        }

        bool leftValid = leftCandidateIdx >= 0 && leftCandidateIdx < n;
        bool rightValid = rightCandidateIdx >= 0 && rightCandidateIdx < n;
        while(leftValid || rightValid)
        {
            if(leftValid && !rightValid)
            {
                res.push_back(calc(a, b, c, nums[leftCandidateIdx--]));
                leftValid = leftCandidateIdx >= 0;
            }
            else if(!leftValid && rightValid)
            {
                res.push_back(calc(a, b, c, nums[rightCandidateIdx++]));
                rightValid = rightCandidateIdx < n;
            }
            else
            {
                double leftDistance = midPoint - nums[leftCandidateIdx];
                double rightDistance = nums[rightCandidateIdx] - midPoint;
                if(leftDistance < rightDistance)
                {
                    res.push_back(calc(a, b, c, nums[leftCandidateIdx--]));
                }
                else
                {
                    res.push_back(calc(a, b, c, nums[rightCandidateIdx++]));
                }
                leftValid = leftCandidateIdx >= 0;
                rightValid = rightCandidateIdx < n;
            }
        }

        if(a < 0) std::reverse(res.begin(), res.end());
        return res;
    }
private:
    int calc(int a, int b, int c, int x)
    {
        return a * x * x + b * x + c;
    }
};

int main() {
    Solution s;
    vector<int> a{-4, -2, 2, 4};
    const auto& r = s.sortTransformedArray(a, -1, 3, 5);
    for(int i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
