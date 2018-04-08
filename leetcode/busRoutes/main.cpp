#include "header.h"

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S == T) return 0;
        int n = routes.size();
        unordered_map<int, unordered_set<int>> stopBuslineMap;
        for(int i = 0; i < n; ++i)
        {
            for(int stop : routes[i])
                stopBuslineMap[stop].insert(i);
        }

        unordered_map<int, bool> visitedStops;
        visitedStops[S] = true;
        int res = 1;
        queue<int> stops;

        for(int line : stopBuslineMap[S])
        {
            for(int stop: routes[line])
            {
                if(visitedStops.find(stop) == visitedStops.end())
                {
                    if(stop == T)
                        return res;
                    stops.push(stop);
                    visitedStops[stop] = true;
                }
            }
        }

        int qsize = stops.size();
        while(!stops.empty())
        {
            ++res;
            for(int i = 0; i < qsize; ++i)
            {
                int nextStop = stops.front();
                stops.pop();

                for(int line : stopBuslineMap[nextStop])
                {
                    for(int stop: routes[line])
                    {
                        if(visitedStops.find(stop) == visitedStops.end())
                        {
                            if(stop == T)
                                return res;
                            stops.push(stop);
                            visitedStops[stop] = true;
                        }
                    }
                }
            }
            qsize = stops.size();
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{
        {1, 2, 7},
        {3, 6, 7}
    };
    std::cout<<s.numBusesToDestination(a, 1, 6)<<std::endl;
}
