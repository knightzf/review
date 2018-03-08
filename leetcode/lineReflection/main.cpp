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
    bool isReflected(vector<pair<int, int>>& points) {
        std::unordered_map<int, std::set<int>> m;
        for(const auto& p : points)
        {
            m[p.second].insert(p.first);
        }

        double midX = 0;
        bool foundMid = false;
        for(const auto& p : m)
        {
            auto iter = p.second.begin();
            auto jter = p.second.rbegin();
            while(*iter < *jter)
            {
                if(foundMid == false)
                {
                    midX = (*iter + *jter) / 2.0;
                    foundMid = true;
                }
                else
                {
                    if((*iter + *jter) / 2.0 != midX)
                    {
                        return false;
                    }
                }

                ++iter;
                ++jter;
            }

            if(*iter == *jter)
            {
                if(foundMid == false)
                {
                    midX = (*iter + *jter) / 2.0;
                    foundMid = true;
                }
                else
                {
                    if((*iter + *jter) / 2.0 != midX)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};


int main() {
    Solution s;
}
