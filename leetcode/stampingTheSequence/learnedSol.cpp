#include "header.h"

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size(), n = target.size();
        unordered_map<char, unordered_set<int>> dict;
        for(int i = 0; i < m; ++i)
        {
            dict[stamp[i]].insert(i);
        }

        vector<int> stampIdx(n, -1);
        function<bool(int)> dfs = [&](int idx)
        {
            if(idx == n) return true;
            for(int j : dict[target[idx]])
            {
                if(idx - j >= 0 && idx + m - j - 1 < n)
                {
                    if(idx == 0 || stampIdx[idx - 1] + 1 == j || stampIdx[idx - 1] == m - 1 || j == 0)
                    {
                        stampIdx[idx] = j;
                        if(dfs(idx + 1)) return true;
                    }                    
                }
            }
            return false;
        };

        if(!dfs(0)) return {};

        for(int i : stampIdx)
            cout<<i<<" ";
        cout<<endl;

        vector<int> up, down;
        for(int i = 0; i < n; ++i)
        {
            if(stampIdx[i] == 0) up.push_back(i);
            else if(i != 0 && stampIdx[i] != stampIdx[i - 1] + 1) down.push_back(i - stampIdx[i]);
        }
        reverse(down.begin(), down.end());
        copy(up.begin(), up.end(), back_inserter(down));
        return down;
    }    
};

int main() {
    Solution s;
    //const auto& r = s.movesToStamp("abca", "aabcaca");
    const auto& r = s.movesToStamp("ffebb", "fffeffebbb");
    for(int i : r)
        cout<< i << " ";
    cout<<endl;
}
