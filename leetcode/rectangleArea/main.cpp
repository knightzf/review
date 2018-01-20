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
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

struct Edge
{
    Edge(int x_, int uy, int ly, int t) :
        x(x_), upY(uy), lowY(ly), type(t)
    {
    }

    bool operator<(const Edge& p) const
    {
        return std::tie(x, type) < std::tie(p.x, p.type);
    }

    int x;
    int upY;
    int lowY;
    int type; // 0 in 1 out
};

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        std::vector<Edge> v{Edge(A, D, B, 0), Edge(C, D, B, 1), Edge(E, H, F, 0), Edge(G, H, F, 1)};
        std::sort(v.begin(), v.end());

        int lastX = 0;
        int height = 0;

        std::multiset<Edge> activeSet;

        int res = 0;

        for(const auto& e : v)
        {
            //std::cout<<e.x<<" "<<e.upY<<" "<<e.lowY<<" "<<e.type<<std::endl;
            if(activeSet.empty())
            {
                activeSet.insert(e);
                height = e.upY - e.lowY;
                lastX = e.x;
            }
            else
            {
                if(e.type == 0)
                {
                    activeSet.insert(e);
                }
                else
                {
                    for(auto iter = activeSet.begin(); iter != activeSet.end(); ++iter)
                    {
                        if(iter->upY == e.upY && iter->lowY == e.lowY)
                        {
                            activeSet.erase(iter);
                            break;
                        }
                    }
                }

                //std::cout<<height<<" "<<(e.x - lastX)<<std::endl;
                res += height * (e.x - lastX);

                height = getHeight(activeSet);
                lastX = e.x;
            }
        }

        return res;
    }

    int getHeight(const std::multiset<Edge>& activeSet)
    {
        if(activeSet.empty()) return 0;

        vector<std::pair<int,int>> yv;
        for(const auto& e : activeSet)
        {
            yv.emplace_back(std::make_pair(e.upY, 0));
            yv.emplace_back(std::make_pair(e.lowY, 1));
        }

        std::sort(yv.begin(), yv.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b){
                    if(a.first == b.first) return a.second < b.second;
                    return a.first > b.first;
                  });

        int startY = 0;
        int res = 0;

        std::multiset<std::pair<int, int>> set;
        for(const auto& p : yv)
        {
            //std::cout<<"he "<<p.first<<" "<<p.second<<std::endl;
            if(set.empty())
            {
                set.insert(p);
                startY = p.first;
            }
            else
            {
                if(p.second == 0)
                {
                    set.insert(p);
                }
                else
                {
                    set.erase(set.begin());

                    if(set.empty())
                    {
                        res += startY - p.first;
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    std::cout<<s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2)<<std::endl;
    std::cout<<s.computeArea(-2, -2, 2, 2, 3, 3, 4, 4)<<std::endl;
    std::cout<<s.computeArea(-2, -2, 2, 2, -1, 4, 1, 6)<<std::endl;
    std::cout<<s.computeArea(-3, -5, 0, -4, -3, -3, 3, 3)<<std::endl;
}
