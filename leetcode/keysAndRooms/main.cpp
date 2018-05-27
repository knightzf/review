#include "header.h"

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> open(n, false);
        open[0] = true;

        queue<int> keys;
        for(int key : rooms[0])
            keys.push(key);

        while(!keys.empty())
        {
            int k = keys.front();
            keys.pop();
            if(!open[k])
            {
                open[k] = true;
                for(int key : rooms[k])
                    keys.push(key);
            }
        }

        for(int i = 0; i < n; ++i)
            if(!open[i]) return false;
        return true;
    }
};

int main()
{
    Solution s;
    //vector<vector<int>> a{{1},{2},{3},{}};
    vector<vector<int>> a{{1, 3},{3, 0, 1},{2},{0}};
    cout<<s.canVisitAllRooms(a)<<endl;
}
