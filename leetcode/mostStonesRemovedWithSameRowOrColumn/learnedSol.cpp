#include "header.h"

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> parent;
        int islands = 0;

        function<int(int)> Find = [&](int id)
        {
            if(parent.count(id) == 0)
            {
                parent[id] = id;
                ++islands;
            }

            if(id != parent[id]) parent[id] = Find(parent[id]);

            return parent[id];
        };

        auto Union = [&](int a, int b)
        {
            int pa = Find(a);
            int pb = Find(b);

            if(pa != pb) {
                parent[pa] = pb;
                --islands; 
            }
        };

        for(auto& p : stones)
        {
            Union(p[0], ~p[1]);
        }

        return stones.size() - islands;
    }
};

int main()
{
    Solution s;
}

