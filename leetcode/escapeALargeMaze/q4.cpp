#include "header.h"

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if(blocked.empty()) return true;
        int m = 1e6;
        set<vector<int>> b(blocked.begin(), blocked.end());
        static vector<int> diff{-1, 0, 1, 0, -1};
        auto canBlock = [&](const vector<int>& p)
        {
            set<vector<int>> visited{p};
            queue<vector<int>> q;
            q.push(p);
            while(!q.empty() && q.size() <= blocked.size()) 
            {
                const auto& pp = q.front();
                for(int k = 0; k < 4; ++k)
                {
                    int i = pp[0] + diff[k], j = pp[1] + diff[k + 1];
                    if(i >= 0 && i < m && j >= 0 && j < m)
                    {
                        vector<int> t{i, j};
                        if(b.count(t) == 0 && visited.count(t) == 0)
                        {
                            visited.insert(t);
                            q.push(t);
                        }
                    }
                }
                q.pop();
            }
            return q.empty();
        };

        if(canBlock(source) || canBlock(target)) return false;
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> b;
    vector<int> a{0, 0};
    vector<int> t{999999,999999};
    cout<<s.isEscapePossible(b, a, t)<<endl;
}
