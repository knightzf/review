#include "header.h"

class Solution {
public:
    double soupServings(int N) {
        if(N >= 6000) return 1;
        std::map<std::pair<int, int>, double> m;
        return impl(N, N, m);
    }

    double impl(int a, int b, std::map<std::pair<int, int>, double>& m)
    {
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1;
        if(b <= 0) return 0;

        const auto& p = std::make_pair(a, b);
        if(m.find(p) != m.end()) return m[p];

        double p1 = impl(a - 100, b, m);
        double p2 = impl(a - 75, b - 25, m);
        double p3 = impl(a - 50, b - 50, m);
        double p4 = impl(a - 25, b - 75, m);

        m[p] = 0.25 * (p1 + p2 + p3 + p4);
        return m[p];
    }
};

int main()
{
    Solution s;
    std::cout<<s.soupServings(6000)<<std::endl;
}
