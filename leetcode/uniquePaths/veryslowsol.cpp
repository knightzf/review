#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>

using namespace std;

class Solution {
public:
    struct Pt
    {
        Pt(int x_, int y_) : x(x_), y(y_)
        {
        }

        bool operator==(const Pt& rhs) const
        {
            return x == rhs.x && y == rhs.y;
        }

        int x;
        int y;
    };

    int uniquePaths(int m, int n)
    {
        int count = 0;

        if(m == 0 || n == 0)
        {
            return count;
        }

        Pt end(m - 1, n - 1);

        std::queue<Pt> q;

        q.push(Pt(0, 0));

        int a = 0;
        while(!q.empty())
        {
            const auto& p = q.front();

            std::cout<<p.x<<" "<<p.y<<std::endl;

            if(++a == 10000000)
                break;
            if(p == end)
            {
                ++count;
            }
            else
            {
                /*if(p.x + 1 > m - 1 && p.y + 1 > n - 1)
                {
                    break;
                }*/

                if(p.x + 1 <= m - 1)
                {
                    q.push(Pt(p.x + 1, p.y));
                }

                if(p.y + 1 <= n - 1)
                {
                    q.push(Pt(p.x, p.y + 1));
                }
            }

            q.pop();
        }

        return count;
    }
};

int main()
{
    Solution sol;
    std::cout<<sol.uniquePaths(4, 7)<<std::endl;
    return 0;
}
