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
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        std::map<int, std::set<int>> widthMap;
        std::map<int, std::set<int>> heightMap;
        for(const auto& p : envelopes)
        {
            widthMap[p.first].insert(p.second);
            heightMap[p.second].insert(p.first);
        }

        std::map<std::pair<int, int>, int> depthMap;
        int maxDepth = 0;
        for(const auto& p : envelopes)
        {
            if(depthMap.find(p) == depthMap.end())
            {
                int r = impl(p, widthMap, heightMap, depthMap, maxDepth);
            }
        }

        return maxDepth;
    }

    int impl(const std::pair<int, int>& p, const std::map<int, std::set<int>>& widthMap,
         const std::map<int, std::set<int>>& heightMap,
         std::map<std::pair<int, int>, int>& depthMap, int& maxDepth)
    {
        if(depthMap.find(p) != depthMap.end()) return depthMap.at(p);

        int temp = 0;
        for(auto iter = widthMap.upper_bound(p.first); iter != widthMap.end(); ++iter)
        {
            auto jter = iter->second.upper_bound(p.second);
            if(jter != iter->second.end())
            {
                temp = max(temp, impl(std::make_pair(iter->first, *jter), widthMap, heightMap, depthMap, maxDepth));
                //break;
            }
        }

        for(auto iter = heightMap.upper_bound(p.second); iter != heightMap.end(); ++iter)
        {
            auto jter = iter->second.upper_bound(p.first);
            if(jter != iter->second.end())
            {
                temp = max(temp, impl(std::make_pair(*jter, iter->first), widthMap, heightMap, depthMap, maxDepth));
                //break;
            }
        }

        depthMap[p] = temp + 1;
        maxDepth = max(maxDepth, temp + 1);
        return temp + 1;
    }
};


int main() {
    Solution s;
    //vector<pair<int, int>> a{{5, 4},{6, 4},{6, 7},{2, 3}};
    vector<pair<int, int>> a{{8,18},{4,14},{16,1},{9,11},{14,15},{12,19},{2,15},{4,4},{18,3},{20,8},{19,18},{18,2},{1,10},{12,1},{10,16},{1,1},{3,19}};
    std::cout<<s.maxEnvelopes(a)<<std::endl;
}
