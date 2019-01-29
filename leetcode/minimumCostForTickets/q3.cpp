#include "header.h"

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int res = INT_MAX;
        set<pair<int, int>> s;

        function<void(int, int)> dfs = [&](int idx, int cost)
        {
            //cout<<idx<<" "<<cost<<endl;
            if(idx >= n)
            {
                res = min(res, cost);
                return;
            }

            const auto& p = make_pair(idx, cost);
            if(s.count(p)) return;
            s.insert(p);

            dfs(idx + 1, cost + costs[0]);

            int day7 = days[idx] + 7 - 1;
            int i = idx;
            while(i < n && days[i] <= day7) ++i;
            if(i > idx + 1)
            {
                //cout<<idx<<" "<<i<<" "<<cost + costs[1]<<endl;
                dfs(i, cost + costs[1]);
            }

            int day30 = days[idx] + 30 - 1;
            i = idx;
            while(i < n && days[i] <= day30) ++i;
            if(i > idx + 1)
            {
                dfs(i, cost + costs[2]);
            }
        };

        dfs(0, 0);
        return res;
    }
};

int main()
{
    Solution s;
    //vector<int> a{1,4,6,7,8,20};
    vector<int> a{1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> b{2, 7, 15};
    cout<<s.mincostTickets(a, b)<<endl;
}

