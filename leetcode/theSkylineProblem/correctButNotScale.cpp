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
#include <iterator>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        std::unordered_map<int, int> indexHeight;

        int startIdx = INT_MAX;
        int endIdx = INT_MIN;

        for(int i = 0; i < n; ++i)
        {
            const auto& v = buildings[i];
            startIdx = min(startIdx, v[0]);
            endIdx = max(endIdx, v[1]);

            for(int j = v[0]; j <= v[1]; ++j)
            {
                //std::cout<<"j "<<j<<std::endl;
                if(indexHeight.find(j) != indexHeight.end())
                {
                    if(v[2] > indexHeight[j])
                    {
                        indexHeight[j] = v[2];
                    }
                }
                else
                {
                    indexHeight[j] = v[2];
                }
            }
        }

        /*for(const auto& p : indexHeight)
        {
            std::cout<<p.first<<" "<<p.second<<" | ";
        }
        std::cout<<std::endl;*/

        vector<pair<int, int>> res;

        int lastHeight = 0;
        for(int i = startIdx; i <= endIdx + 1; ++i)
        {
            if(indexHeight.find(i) != indexHeight.end())
            {
                int height = indexHeight[i];
                if(height != lastHeight)
                {
                    if(height > lastHeight)
                        res.push_back(std::make_pair(i, height));
                    else
                        res.push_back(std::make_pair(i - 1, height));
                }

                lastHeight = height;
            }
            else
            {
                if(lastHeight != 0)
                {
                    res.push_back(std::make_pair(i - 1, 0));
                }

                lastHeight = 0;
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a{ {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8} };
    const auto& b = s.getSkyline(a);
    for(const auto& p : b)
    {
        std::cout<<p.first<<" "<<p.second<<"|";
    }
    std::cout<<std::endl;
}
