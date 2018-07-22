#include "header.h"

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, unordered_set<int>> m;
        for(const auto& v : obstacles)
        {
            m[v[0]].insert(v[1]);
        }

        int x = 0, y = 0;
        pair<int, int> direction = {0, 1};
        int res = 0;
        for(int c : commands)
        {
            if(c > 0)
            {
                for(int i = 0; i < c; ++i)
                {
                    int a = x + direction.first;
                    int b = y + direction.second;
                    if(m.count(a) && m[a].count(b)) break;
                    x = a;
                    y = b;
                    res = max(res, a * a + b * b);
                }
            }
            else if(c == -2)
            {
                if(direction.second != 0)
                {
                    direction.first *= -1;
                    direction.second *= -1;
                }
                swap(direction.first, direction.second);
            }
            else if(c == -1)
            {
                if(direction.first != 0)
                {
                    direction.first *= -1;
                    direction.second *= -1;
                }
                swap(direction.first, direction.second);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
