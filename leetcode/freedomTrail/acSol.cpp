#include "header.h"

class Solution {
private:
    int minSteps;
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        vector<set<int>> v(26);
        for(int i = 0; i < n; ++i)
        {
            v[ring[i] - 'a'].insert(i);
        }

        minSteps = INT_MAX;
        vector<unordered_map<int, int>> res(key.size());
        impl(v, key, n, res, 0, 0, 0);
        return minSteps;
    }

    void impl(vector<set<int>>& v, string& key, int n, vector<unordered_map<int, int>>& res,
              int idx, int i, int cnt)
    {
        if(i == key.size())
        {
            minSteps = min(minSteps, cnt);
            return;
        }

        if(res[i].count(idx) == 0 || res[i][idx] > cnt)
            res[i][idx] = cnt;
        else
            return;

        const auto& s = v[key[i] - 'a'];
        auto iter = s.lower_bound(idx);
        if(iter != s.end() && *iter == idx)
        {
            return impl(v, key, n, res, idx, i + 1, cnt + 1);
        }

        int prevIdx = -1;
        if(iter == s.begin())
            prevIdx = *s.rbegin();
        else
        {
            auto jter = iter;
            --jter;
            prevIdx = *jter;
        }

        int posIdx = -1;
        if(iter != s.end())
            posIdx = *iter;
        else
            posIdx = *s.begin();

        int prevSteps = prevIdx < idx ? (idx - prevIdx) : (idx + n - prevIdx);
        int posSteps = posIdx > idx ? (posIdx - idx) : (n - idx + posIdx);

        if(prevIdx == posIdx)
        {
            return impl(v, key, n, res, prevIdx, i + 1, cnt + min(prevSteps, posSteps) + 1);
        }

        impl(v, key, n, res, prevIdx, i + 1, cnt + prevSteps + 1);
        impl(v, key, n, res, posIdx, i + 1, cnt + posSteps + 1);
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
