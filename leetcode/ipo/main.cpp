#include "header.h"

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<pair<int, int>> v;
        int n = Profits.size();

        for(int i = 0; i < n; ++i)
            v.emplace_back(Profits[i], Capital[i]);

        sort(v.begin(), v.end(), [](const auto& a, const auto& b){
                return a.second < b.second;
             });

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) { return a.first < b.first;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

        int capital = W;
        int j = 0;
        for(int i = 0; i < k; ++i)
        {
            while(j < n && v[j].second <= capital)
            {
                q.push(v[j]);
                ++j;
            }

            if(!q.empty())
            {
                capital += q.top().first;
                q.pop();
            }
        }
        return capital;
    }
};

int main()
{
    Solution s;
}
