#include "header.h"

class TopVotedCandidate {
private:
    map<int, int> m;

    struct Vote{
        int person;
        int count;
        int time;
    };

public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        unordered_map<int, int> voteCnt;
        auto cmp = [](const Vote& a, const Vote& b)
        {
            if(a.count < b.count) return true;
            if(a.count == b.count) return a.time < b.time;
            return false;
        };
        priority_queue<Vote, vector<Vote>, decltype(cmp)> q(cmp);

        for(int i = 0, n = persons.size(); i < n; ++i)
        {
            ++voteCnt[persons[i]];
            q.push(Vote{persons[i], voteCnt[persons[i]], times[i]});
            m[times[i]] = q.top().person;
        }
    }
    
    int q(int t) {
        auto iter = m.lower_bound(t);
        if(iter == m.end()) return m.rbegin()->second;
        if(iter->first == t) return iter->second;
        --iter; return iter->second;
    }
};


int main()
{
    //Solution s;
}
