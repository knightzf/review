#include "header.h"

class Solution {
private:
    int minSteps;
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        unordered_map<char, vector<pair<int, int>>> map;
        for(int i = 0; i < n; ++i)
            map[ring[i]].push_back({i, INT_MAX});

        int m = key.size();
        vector<pair<int, int>> cntV{{0, 0}};
        int res;
        for(int i = 0; i < m; ++i)
        {
            if(i != 0 && key[i] == key[i - 1]) continue;

            char c = key[i];
            vector<pair<int, int>> t = map[c];
            res = INT_MAX;
            for(int j = 0; j < t.size(); ++j)
            {
                for(int k = 0; k < cntV.size(); ++k)
                {
                    int dis = abs(cntV[k].first - t[j].first);
                    dis = min(dis, n - dis);
                    t[j].second = min(t[j].second, cntV[k].second + dis);
                    res = min(res, t[j].second);
                }
            }

            cntV = t;
        }
        return res + m;
    }
};

int main()
{
    Solution s;
    //cout<<s.findRotateSteps("edcba", "abcde")<<endl;
    //cout<<s.findRotateSteps("caotmcaataijjxi", "oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx")<<endl;
    //cout<<s.findRotateSteps("iotfo", "fioot")<<endl;
    cout<<s.findRotateSteps("abhuzbtadgsrhem", "zhbubbdtazmsabbddasbehagahrhhhmmetuzsrugrateg")<<endl;
    //s.findRotateSteps("daudr", "urdda");
}
