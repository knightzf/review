#include "header.h"

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> m;
        for(char c : S) ++m[c];
        priority_queue<pair<int, char>, vector<pair<int, char>>> q;
        for(const auto& p : m) q.push(make_pair(p.second, p.first));
        string res;
        while(!q.empty()) {
            auto t = q.top();
            if(res.empty() || res.back() != t.second) {
                res += t.second;
                q.pop();
                if(t.first > 1) q.push({t.first - 1, t.second});
                continue;
            }
            q.pop();
            if(q.empty()) return "";
            res += q.top().second;
            auto s = q.top();
            q.pop();
            if(s.first > 1) q.push({s.first - 1, s.second});
            q.push(t);
        }
        return res;
    }
};

int main()
{
    //Solution s;
}