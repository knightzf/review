#include "header.h"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> v(numCourses);
        for(const auto& p : prerequisites) {
            int course = p[0], pre = p[1];
            v[pre].insert(course);
        }
        vector<int> indegree(numCourses, 0);
        for(const auto& p : v) {
            for(int course : p) ++indegree[course];
        }

        vector<int> res;
        unordered_set<int> free;
        for(int i = 0; i < numCourses; ++i) {
            if(!indegree[i]) free.insert(i);
        }
        while(!free.empty()) {
            int pre = *free.begin();
            res.push_back(pre);
            free.erase(pre);
            for(int course : v[pre]) {
                --indegree[course];
                if(indegree[course] == 0) free.insert(course);
            }
        }
        return res.size() == numCourses ? res : vector<int>{};
    }
};

int main()
{
    //Solution s;
}