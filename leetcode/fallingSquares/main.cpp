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
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        std::multimap<int, int> s;
        vector<int> res;
        int maxHeight = 0;
        for(int i = 0; i < positions.size(); ++i)
        {
            if(s.empty())
            {
                s.insert(std::make_pair(positions[i].first, positions[i].second));
                s.insert(std::make_pair(positions[i].first + positions[i].second, -positions[i].second));
                maxHeight = positions[i].second;
            }
            else
            {
                auto endIter = s.lower_bound(positions[i].first + positions[i].second);
                std::multimap<int, int> activeSet;
                for(auto iter = s.begin(); iter != endIter; ++iter)
                {
                    if(iter->second < 0 && iter->first <= positions[i].first)
                    {
                        activeSet.erase(-iter->second);
                    }
                    else
                    {
                        activeSet.insert(std::make_pair(iter->second, iter->first));
                    }
                }

                int h = activeSet.empty() ? positions[i].second :
                    activeSet.rbegin()->first + positions[i].second;
                s.insert(std::make_pair(positions[i].first, h));
                s.insert(std::make_pair(positions[i].first + positions[i].second, -h));

                maxHeight = std::max(maxHeight, h);
            }
            //std::cout<<maxHeight<<std::endl;
            res.push_back(maxHeight);
        }

        return res;
    }
};

int main() {
    Solution s;
    //vector<pair<int, int>> a{{1, 2},{2, 3},{6, 1}};
    //vector<pair<int, int>> a{{100, 100},{200, 100}};
    vector<pair<int, int>> a{{9, 6},{2, 2},{2, 6}};
    const auto& r = s.fallingSquares(a);
    for(auto i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
