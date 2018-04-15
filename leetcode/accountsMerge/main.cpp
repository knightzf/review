#include "header.h"

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n, -1);

        unordered_map<string, int> m;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 1; j < accounts[i].size(); ++j)
            {
                int currentParent = getParentIdx(parent, i);
                if(m.find(accounts[i][j]) == m.end())
                {
                    m[accounts[i][j]] = currentParent;
                }
                else
                {
                    int existingParent = getParentIdx(parent, m[accounts[i][j]]);
                    if(currentParent != existingParent)
                    {
                        parent[max(currentParent, existingParent)] = min(currentParent, existingParent);
                    }
                }
            }
        }
        //for(int i : parent)
        //std::cout<<i<<" ";
        //std::cout<<std::endl;

        unordered_map<int, set<string>> resMap;
        for(const auto& p : m)
        {
            resMap[getParentIdx(parent, p.second)].insert(p.first);
        }

        vector<vector<string>> res;
        for(const auto& p : resMap)
        {
            vector<string> t{accounts[p.first][0]};
            t.insert(t.end(), p.second.begin(), p.second.end());
            res.emplace_back(t);
        }
        return res;
    }

    int getParentIdx(vector<int>& parent, int i)
    {
        if(parent[i] == -1)
            parent[i] = i;

        while(parent[i] != i)
        {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }

        return i;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> a{{"David","David0@m.co","David1@m.co"},{"David","David3@m.co","David4@m.co"},{"David","David4@m.co","David5@m.co"},{"David","David2@m.co","David3@m.co"},{"David","David1@m.co","David2@m.co"}};
    const auto& r = s.accountsMerge(a);
    for(const auto& i : r)
    {
        for(const auto& j : i)
            std::cout<<j<<" ";
        std::cout<<std::endl;
    }
}
