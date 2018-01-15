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
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses == 0) return vector<int>();
        if(numCourses == 1) return vector<int>{0};

        std::vector<int> depDegree(numCourses, 0);
        std::unordered_map<int, std::vector<int>> courseMap;
        for(const auto& p : prerequisites)
        {
            ++depDegree[p.first];
            courseMap[p.second].push_back(p.first);
        }

        std::queue<int> q;
        for(int i = 0; i < numCourses; ++i)
        {
            if(depDegree[i] == 0) q.push(i);
        }

        vector<int> res;

        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            res.push_back(t);

            if(courseMap.find(t) != courseMap.end())
            {
                for(int p : courseMap[t])
                {
                    --depDegree[p];
                    if(depDegree[p] == 0)
                    {
                        q.push(p);
                    }
                }
            }
        }

        if(res.size() != numCourses)
        {
            return vector<int>();
        }

        return res;
    }
};


int main() {
    Solution s;
}
