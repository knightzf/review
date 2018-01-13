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
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses < 2) return true;

        std::unordered_map<int, std::vector<int>> courseMap;
        for(const auto& p : prerequisites)
        {
            courseMap[p.first].push_back(p.second);
        }

        for(const auto& p : prerequisites)
        {
            std::unordered_set<int> trackSet;

            if(!dfs(p.first, trackSet, courseMap))
            {
                return false;
            }
        }

        return true;
    }

    bool dfs(int start, std::unordered_set<int>& trackSet,
             const std::unordered_map<int, std::vector<int>>& courseMap)
    {
        if(trackSet.find(start) != trackSet.end())
        {
            return false;
        }

        if(courseMap.find(start) != courseMap.end())
        {
            trackSet.insert(start);

            const auto& reqV = courseMap.at(start);
            for(auto reqCourse : reqV)
            {
                if(!dfs(reqCourse, trackSet, courseMap))
                {
                    return false;
                }
            }

            trackSet.erase(start);
        }

        return true;
    }
};


int main() {
    Solution s;
}
