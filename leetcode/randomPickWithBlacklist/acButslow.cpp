#include "header.h"

class Solution {
private:
    int cnt = 0;
    vector<pair<int, int>> v;
public:
    Solution(int N, vector<int> blacklist) {
        if(blacklist.empty())
        {
            v.emplace_back(make_pair(0, N - 1));
            cnt = N;
            return;
        }
        
        sort(blacklist.begin(), blacklist.end());
        
        if(!blacklist.empty() && blacklist[0] != 0)
        {
            cnt += blacklist[0];
            v.emplace_back(make_pair(0, blacklist[0] - 1));
        }
                
        for(int i = 1, n = blacklist.size(); i < n; ++i)
        {
            if(blacklist[i] != blacklist[i - 1])
            {
                cnt += blacklist[i] - 1 - blacklist[i - 1];
                v.emplace_back(make_pair(blacklist[i - 1] + 1, blacklist[i] - 1));
            }
        }

        if(!blacklist.empty() && blacklist.back() != N - 1)
        {
            cnt += N - 1 - blacklist.back();
            v.emplace_back(make_pair(blacklist.back() + 1, N - 1));
        }
    }
    
    int pick() {
        if(cnt == 0) return 0;
        int t = rand() % cnt;
        int i = 0;
        while(true)
        {
            if(t + 1 - (v[i].second - v[i].first + 1) <= 0)
            {
                return v[i].first + t;
            }
            t -= v[i].second - v[i].first + 1;
            ++i;
        }
    }
};

int main() {
    //Solution s;
}
