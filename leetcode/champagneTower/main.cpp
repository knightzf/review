#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        std::vector<std::vector<double>> m(100, vector<double>(100, INT_MIN));
        m[0][0] = poured;
        double res = impl(poured, query_row, query_glass, m);
        return res > 1 ? 1 : res;
    }

    double impl(int poured, int query_row, int query_glass,
                std::vector<std::vector<double>>& m)
    {
        if(m[query_row][query_glass] != INT_MIN) return m[query_row][query_glass];

        double res = 0;
        if(query_row > 0)
        {
            if(query_glass == 0)
            {
                double total = impl(poured, query_row - 1, query_glass, m);
                if(total > 1) res = (total - 1)/2.0;
            }
            else if(query_glass == query_row)
            {
                double total = impl(poured, query_row - 1, query_glass - 1, m);
                if(total > 1) res = (total - 1)/2.0;
            }
            else
            {
                double total = impl(poured, query_row - 1, query_glass, m);
                if(total > 1) res = (total - 1)/2.0;
                total = impl(poured, query_row - 1, query_glass - 1, m);
                if(total > 1) res += (total - 1)/2.0;
            }
        }

        m[query_row][query_glass] = res;

        return res;
    }
};

int main() {
    Solution s;
    std::cout<<s.champagneTower(1, 1, 1)<<std::endl;
    std::cout<<s.champagneTower(2, 1, 1)<<std::endl;
    std::cout<<s.champagneTower(2, 0, 0)<<std::endl;
    std::cout<<s.champagneTower(4, 2, 0)<<std::endl;
    std::cout<<s.champagneTower(100, 85, 39)<<std::endl;
}
