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
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>

using namespace std;

class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K)
    {
        if(heights.empty() || V == 0) return heights;

        if(heights.size() == 1)
        {
            heights[0] += V;
            return heights;
        }

        int n = heights.size();

        if(K == 0)
        {
            for(int i = 0; i < V; ++i)
            {
                if(heights[K] < heights[K + 1])
                {
                    ++heights[K];
                }
                else
                {
                    ++heights[minRight(heights, K, n)];
                }
            }
        }
        else if(K == n - 1)
        {
            for(int i = 0; i < V; ++i)
            {
                if(heights[K] < heights[K - 1])
                {
                    ++heights[K];
                }
                else
                {
                    ++heights[minLeft(heights, K, n)];
                }
            }
        }
        else
        {
            for(int i = 0; i < V; ++i)
            {
                if(heights[K] < heights[K + 1] && heights[K] < heights[K - 1])
                {
                    ++heights[K];
                }
                else
                {
                    int minLeftIdx = minLeft(heights, K, n);
                    int minRightIdx = minRight(heights, K, n);

                    if(heights[minLeftIdx] < heights[K])
                    {
                        ++heights[minLeftIdx];
                    }
                    else if(heights[minRightIdx] < heights[K])
                    {
                        ++heights[minRightIdx];
                    }
                    else
                    {
                        ++heights[K];
                    }
                }

                for(auto i : heights)
                {
                    std::cout<<i<<" ";
                }
                std::cout<<std::endl;
            }
        }

        return heights;
    }
private:
    int minRight(const vector<int>& heights, int idx, int n)
    {
        int minVal = heights[idx];
        int minIdx = idx;

        for(int i = idx + 1; i < n; ++i)
        {
            if(heights[i] < minVal)
            {
                minVal = heights[i];
                minIdx = i;
            }
            else if(heights[i] == minVal)
            {

            }
            else
            {
                break;
            }
        }

        return minIdx;
    }

    int minLeft(const vector<int>& heights, int idx, int n)
    {
        int minVal = heights[idx];
        int minIdx = idx;

        for(int i = idx - 1; i >= 0; --i)
        {
            if(heights[i] < minVal)
            {
                minVal = heights[i];
                minIdx = i;
            }
            else if(heights[i] == minVal)
            {

            }
            else
            {
                break;
            }
        }

        return minIdx;
    }
};

int main()
{
    Solution s;
    //vector<int> a{1,2,3,4,3,2,1,2,3,4,3,2,1};
    vector<int> a{1,2,3,4,3,2,1,2,3,4,3,2,1};
    auto r = s.pourWater(a, 5, 2);
    for(auto i : r)
    {
        //std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
