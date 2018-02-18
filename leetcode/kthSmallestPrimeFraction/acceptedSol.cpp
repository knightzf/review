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

struct Fraction
{
    Fraction(int i_, int j_, int no_, int de_):
        i(i_), j(j_), nominator(no_), denominator(de_)
    {
    }

    bool operator<(const Fraction& r) const
    {
        return nominator * r.denominator < r.nominator * denominator;
    }

    int i;
    int j;
    int nominator;
    int denominator;
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        std::sort(A.begin(), A.end());
        int n = A.size();
        std::set<Fraction> s;
        for(int i = 0; i < n - 1; ++i)
        {
            s.insert(Fraction(i, n - 1, A[i], A[n - 1]));
        }

        int cnt = 0;
        vector<int> res;
        while(true)
        {
            ++cnt;
            const auto& f = *s.begin();
            if(cnt == K)
            {
                res.push_back(f.nominator);
                res.push_back(f.denominator);
                break;
            }
            else
            {
                if(f.j - 1 > f.i)
                {
                    s.insert(Fraction(f.i, f.j - 1, A[f.i], A[f.j - 1]));
                }

                s.erase(f);
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> a{1, 2, 3, 5};
    std::cout<<s.kthSmallestPrimeFraction(a, 3)[1]<<std::endl;
}
