#include "header.h"

class Solution {
public:
    int racecar(int target) {
        function<int(int)> f = [&](int t) {
            static unordered_map<int, int> m;
            if(m.count(t)) return m[t];
            m[t] = INT_MAX;

            int x = t + 1;
            if(x == (x & -x)) m[t] = log2(x);
            else {
                int steps = 1;
                for(; (1 << steps) - 1 < t; ++steps) {
                    for(int j = 0; j < steps; ++j) {
                        m[t] = min(m[t],
                            steps + j + 2 + f(t - (1 << steps) + (1 << j)));
                    }
                }
                m[t] = min(m[t], steps + 1 + f((1 << steps) - 1 - t));
            }

            return m[t];
        };

        return f(target);
    }
};

int main()
{
    //Solution s;
}