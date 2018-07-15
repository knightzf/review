#include "header.h"

class Solution {
public:
    int minRefuelStops(int target, int startFuel, const vector<vector<int>>& stations) {
        if(startFuel >= target) return 0;

        int n = stations.size();
        deque<pair<int, int>> q;
        for(int i = 0; i < n; ++i)
        {
            if(startFuel - stations[i][0] >= 0)
            {
                q.push_back({i, startFuel - stations[i][0] + stations[i][1]});
            }
            else
            {
                break;
            }
        }
        int qsize = q.size();
        int stops = 1;
        while(qsize)
        {
            for(int i = 0; i < qsize; ++i)
            {
                const auto& p = q.front();
                if(p.second >= target - stations[p.first][0]) return stops;

                for(int j = p.first + 1; j < n; ++j)
                {
                    if(p.second >= stations[j][0] - stations[p.first][0])
                    {
                        q.push_back({j, p.second - stations[j][0] + stations[p.first][0] + stations[j][1]});
                    }
                    else
                    {
                        break;
                    }
                }
                q.pop_front();
            }

            qsize = q.size();
            ++stops;
        }

        return -1;
    }

};

int main()
{
    Solution s;
    //cout<<s.minRefuelStops(1, 1, {{}})<<endl;
    //cout<<s.minRefuelStops(100, 1, {{10,100}})<<endl;
    //cout<<s.minRefuelStops(100, 10, {{10,60}, {20, 30}, {30, 30}, {60, 40}})<<endl;
    //cout<<s.minRefuelStops(100, 25, {{25,25}, {50, 25}, {75, 25}})<<endl;
    cout<<s.minRefuelStops(1000, 36, {{7,13},{10,11},{12,31},{22,14},{32,26},{38,16},{50,8},{54,13},{75,4},{85,2},{88,35},{90,9},{96,35},{103,16},{115,33},{121,6},{123,1},{138,2},{139,34},{145,30},{149,14},{160,21},{167,14},{188,7},{196,27},{248,4},{256,35},{262,16},{264,12},{283,23},{297,15},{307,25},{311,35},{316,6},{345,30},{348,2},{354,21},{360,10},{362,28},{363,29},{367,7},{370,13},{402,6},{410,32},{447,20},{453,13},{454,27},{468,1},{470,8},{471,11},{474,34},{486,13},{490,16},{495,10},{527,9},{533,14},{553,36},{554,23},{605,5},{630,17},{635,30},{640,31},{646,9},{647,12},{659,5},{664,34},{667,35},{676,6},{690,19},{709,10},{721,28},{734,2},{742,6},{772,22},{777,32},{778,36},{794,7},{812,24},{813,33},{815,14},{816,21},{824,17},{826,3},{838,14},{840,8},{853,29},{863,18},{867,1},{881,27},{886,27},{894,26},{917,3},{953,6},{956,3},{957,28},{962,33},{967,35},{972,34},{984,8},{987,12}})<<endl;
}
