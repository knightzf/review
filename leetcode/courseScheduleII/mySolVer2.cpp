#include "header.h"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses == 0) return vector<int>();
        vector<int> degree(numCourses, 0);
        unordered_map<int, vector<int>> m;
        for(const auto& p : prerequisites)
        {
            m[p.second].push_back(p.first);
            ++degree[p.first];
        }

        vector<int> res;

        for(int i = 0; i < numCourses; ++i)
        {
            if(degree[i] == 0)
            {
                dfs(i, degree, m, res);
            }
        }

        for(int i = 0; i < numCourses; ++i)
        {
            if(degree[i] != 0 && degree[i] != INT_MAX)
                return vector<int>();
        }

        return res;
    }

    void dfs(int i, vector<int>& degree, unordered_map<int, vector<int>>& m, vector<int>& res)
    {
        degree[i] = INT_MAX;
        res.push_back(i);
        if(m.find(i) != m.end())
        {
            for(int j : m[i])
            {
                --degree[j];
                if(degree[j] == 0)
                {
                    dfs(j, degree, m, res);
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<pair<int, int>> a{{1, 0}};
    const auto& r = s.findOrder(2, a);
    for(int i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
