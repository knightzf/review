#include "header.h"

struct Cmp{
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const
    {
        if(a.second > b.second) return true;
        if(a.second == b.second) return a.first < b.first;
        return false;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        set<pair<string, int>, Cmp> s;
        for(const auto& w : words)
        {
            ++m[w];
            if(s.size() < k || m[w] >= s.rbegin()->second)
            {
                const auto& p = make_pair(w, m[w] - 1);
                if(s.count(p))
                {
                    s.erase(p);
                }

                s.insert(make_pair(w, m[w]));
                if(s.size() > k)
                {
                    s.erase(std::prev(s.end()));
                }
            }
        }

        vector<string> res;
        res.reserve(k);
        for(auto& p : s)
            res.push_back(p.first);
        return res;
    }
};

int main() {
    //Solution s;
}
