#include "header.h"

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> m;
        for(const auto& edge : edges)
        {
            m[edge[0]].insert(edge[1]);
            m[edge[1]].insert(edge[0]);
        }

        vector<int> distance(N, -1);
        queue<int> q;
        q.push(0);
        int d = 0;
        int qsize = q.size();
        while(!q.empty())
        {
            for(int i = 0; i < qsize; ++i)
            {
                int t = q.front();
                q.pop();
                distance[t] = d;

                for(int j : m[t])
                {
                    if(distance[j] == -1)
                        q.push(j);
                }

            }
            ++d;
            qsize = q.size();
        }

        vector<vector<int>> dp(N, vector<int>(N, -1));
        for(int i = 0; i < N; ++i)
        {
            dp[0][i] = distance[i];
            dp[i][0] = distance[i];
        }

        for(int i = 1; i < N; ++i)
        {
            dp[i][i] = 0;
        }

        for(const auto& p : m)
        {
            for(int i : p.second)
                dp[p.first][i] = 1;
        }

        for(int i = 1; i < N; ++i)
        {
            for(int j = i + 1; j < N; ++j)
            {
                if(j != i && m[i].find(j) == m[i].end() && dp[i][j] == -1)
                {
                    dp[i][j] = INT_MAX;
                    for(int k = 0; k < N; ++k)
                    {
                        if(dp[k][i] != -1 && dp[k][j] != -1)
                        {
                            dp[i][j] = min(dp[i][j], dp[k][i] + dp[k][j]);
                        }
                    }
                    dp[j][i] = dp[i][j];
                }
            }
        }

        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < N; ++j)
                std::cout<<dp[i][j]<<" ";
            cout<<endl;
        }

        vector<int> res;
        for(int i = 0; i < N; ++i)
            res.push_back(accumulate(dp[i].begin(), dp[i].end(), 0));
        return res;
    }
};

int main()
{
    Solution s;
    /*vector<vector<int>> a {{0,1},{0,2},{2,3},{2,4},{2,5}};
    const auto& res = s.sumOfDistancesInTree(6, a);*/
    vector<vector<int>> a {{2,3},{0,3},{4,1},{4,3}};
    const auto& res = s.sumOfDistancesInTree(5, a);
    for(int i : res)
        std::cout<<i<<" ";
    std::cout<<endl;
}
