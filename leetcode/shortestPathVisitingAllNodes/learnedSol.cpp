#include "header.h"

class Solution {
public:
    using State = pair<int, int>;

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        int target = 0;
        for(int i = 0; i < n; ++i)
            target = target | (1 << i);

        map<State, int> m;
        queue<State> q;
        for(int i = 0; i < n; ++i)
        {
            const State& t = make_pair(1 << i, i);
            q.push(t);
            m[t] = 0;
        }

        int steps = 0;
        int qsize = q.size();
        while(qsize)
        {
            for(int i = 0; i < qsize; ++i)
            {
                auto state = q.front();
                if(state.first == target) return steps;
                q.pop();

                for(int next : graph[state.second])
                {
                    const State& t = make_pair(state.first | (1 << next), next);
                    if(m.find(t) == m.end() || m[t] > steps + 1)
                    {
                        m[t] = steps + 1;
                        q.push(t);
                    }
                }
            }
            qsize = q.size();
            ++steps;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    //vector<vector<int>> a{{1, 2, 3},{0},{0},{0}};
    vector<vector<int>> a{{2,10},{2,7},{0,1,3,4,5,8},{2},{2},{2},{8},{9,11,8,1},{7,6,2},{7},{11,0},{7,10}};
    cout<<s.shortestPathLength(a)<<endl;
}
