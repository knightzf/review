#include "header.h"

class Solution {
public:
    struct State {
        int leftIdx;
        int rightIdx;
        int power;
        int points;
        tuple<int, int, int> key() const
        {
            return make_tuple(leftIdx, rightIdx, power);
        }
    };

    int bagOfTokensScore(vector<int>& tokens, int P) {
        if(tokens.empty()) return 0;
        sort(tokens.begin(), tokens.end());
        if(P < tokens[0]) return 0;
        
        int res = 0;
        State s{0, (int)tokens.size() - 1, P, 0};
        map<tuple<int, int, int>, int> m;
        function<void(const State& s)> dfs = [&](const State& s)
        {
            res = max(res, s.points);            
            if(m.find(s.key()) != m.end() && m[s.key()] >= s.points) return;
             m[s.key()] = s.points;
            if(s.leftIdx == s.rightIdx)
            {
                if(s.power >= tokens[s.leftIdx])
                {
                    res = max(res, s.points + 1);
                }
            }
            else if(s.leftIdx < s.rightIdx)
            {
                if(s.power >= tokens[s.leftIdx])
                {
                    State t = s;
                    t.power -= tokens[s.leftIdx];
                    ++t.leftIdx;
                    ++t.points;
                    dfs(t);
                }
                if(s.points > 0)
                {
                    State t = s;
                    --t.points;
                    t.power += tokens[s.rightIdx];
                    --t.rightIdx;
                    dfs(t);
                }
            }            
        };

        dfs(s);
        
        return res;
    }
};

int main()
{
    Solution s;
}
