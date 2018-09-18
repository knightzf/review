#include "header.h"

class Solution {
private:
    int cnt = 0;
    multimap<int, int> s;
public:
    Solution(int N, vector<int> blacklist) {        
        sort(blacklist.begin(), blacklist.end());

        s.emplace(0, -1);
        for(int i = 0, n = blacklist.size(); i < n; ++i) {
            if(i == 0) {
                s.emplace(blacklist[i], blacklist[i]);
                cnt += blacklist[i];
            }
            else {
                int lastVal = blacklist[i - 1];
                if(blacklist[i] == lastVal + 1) {
                    s.emplace(s.rbegin()->first, blacklist[i]);
                }
                else {
                    s.emplace(s.rbegin()->first + blacklist[i] - lastVal - 1, blacklist[i]);
                    cnt += blacklist[i] - lastVal - 1;
                }
            }
        }

        if(!blacklist.empty()) {
            s.emplace(s.rbegin()->first + N - blacklist.back() - 1, N);
            cnt += N - blacklist.back() - 1;
        }
        else {
            s.emplace(N, N);
            cnt += N;
        }
    }
    
    int pick() {
        int t = rand() % cnt + 1;
        auto iter = s.lower_bound(t);
        auto jter = iter; --jter;
        return jter->second + t - jter->first;
    }
};

int main() {
    //Solution s;
}
