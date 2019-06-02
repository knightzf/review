#include "header.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> depMap;
        for(const auto& v : prerequisites) {
            int course = v[0], pre = v[1];
            depMap[pre].insert(course);
        }
        vector<int> indegree(numCourses, 0);
        for(const auto& p : depMap) 
            for(int course : p.second) ++indegree[course];
        unordered_set<int> free;
        for(int i = 0; i < numCourses; ++i) {
            if(!indegree[i]) free.insert(i);
        }
        int count = 0;
        while(!free.empty()) {
            int pre = *free.begin();
            free.erase(pre);
            ++count;
            for(int course : depMap[pre]) {
                --indegree[course];
                if(indegree[course] == 0) free.insert(course);
            }
        }
        return count == numCourses;
    }
};

int main()
{
    Solution s;
}