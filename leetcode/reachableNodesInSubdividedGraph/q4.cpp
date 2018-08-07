#include "header.h"

class Solution {
public:
    using Cnt = vector<int>;
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        unordered_map<int, unordered_map<int, Cnt*>> m;
        for(const auto& e : edges)
        {
            Cnt* cnt = new Cnt{0, 0, e[2]};
            m[e[0]][e[1]] = cnt;
            m[e[1]][e[0]] = cnt;
        }

        int res = 0;
        vector<int> visited(N, -1);
        queue<pair<int, int>> q;
        q.push({0, M});
        int qsize = q.size();
        while(!q.empty())
        {
            for(int i = 0; i < qsize; ++i)
            {
                auto t = q.front();
                q.pop();

                int idx = t.first;
                int steps = t.second;

                if(visited[idx] == -1)
                    ++res;
                if(visited[idx] > t.second) continue;
                visited[idx] = t.second;

                for(const auto& next : m[idx])
                {
                    int jdx = next.first;
                    auto& cnt = *m[idx][jdx];
                    if(steps > cnt[2])
                    {
                        if(cnt[0] + cnt[1] < cnt[2])
                        {
                            res += cnt[2] - cnt[0] - cnt[1];
                            if(idx < jdx)
                            {
                                cnt[0] = cnt[2] - cnt[1];
                            }
                            else
                            {
                                cnt[1] = cnt[2] - cnt[0];
                            }
                        }
                        if(steps - cnt[2] - 1 > visited[jdx])
                            q.push({jdx, steps - cnt[2] - 1});
                    }
                    else
                    {
                        if(cnt[0] + cnt[1] < cnt[2])
                        {
                            if(idx < jdx)
                            {
                                if(steps > cnt[0])
                                {
                                    res += min(steps, cnt[2] - cnt[1]) - cnt[0];
                                    cnt[0] = min(steps, cnt[2] - cnt[1]);
                                }
                            }
                            else
                            {
                                if(steps > cnt[1])
                                {
                                    res += min(steps, cnt[2] - cnt[0]) - cnt[1];
                                    cnt[1] = min(steps, cnt[2] - cnt[0]);
                                }
                            }
                        }
                    }
                }
            }
            qsize = q.size();
        }

        for(auto & p : m)
        {
            for(auto& q : p.second)
            {
                if(p.first < q.first)
                    cout<<p.first <<" "<<q.first<<" "<<
                        (*q.second)[0] << " " << (*q.second)[1] << " "<<(*q.second)[2] <<endl;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    //if(0)
    {
        vector<vector<int>> a{{0,1,10},{0,2,1},{1,2,2}};
        cout<<s.reachableNodes(a, 6, 3)<<endl;
    }
    {
        vector<vector<int>> a{{0,2,3},{0,4,4},{2,3,8},{1,3,5},{0,3,9},{3,4,6},{0,1,5},{2,4,6},{1,2,3},{1,4,1}};
        cout<<s.reachableNodes(a, 8, 5)<<endl;
    }

}
