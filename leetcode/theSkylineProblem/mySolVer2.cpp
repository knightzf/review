#include "header.h"

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> m;
        for(const auto& v : buildings)
        {
            m.push_back(std::make_pair(v[0], v[2]));
            m.push_back(std::make_pair(v[1], -v[2]));
        }

        std::sort(m.begin(), m.end(), [](const pair<int, int>& a, const pair<int, int>& b){
                    if(a.first < b.first) return true;
                    else if(a.first == b.first) return a.second > b.second;
                    return false;
                  });

        vector<pair<int, int>> res;
        std::multimap<int, int> mm;
        for(const auto& p : m)
        {
            if(mm.empty())
            {
                mm.emplace(p.second, p.first);
                res.push_back(std::make_pair(p.first, p.second));
            }
            else
            {
                if(p.second < 0)
                {
                    mm.erase(mm.equal_range(-p.second).first);
                }
                else
                {
                    mm.emplace(p.second, p.first);
                }

                if(mm.empty())
                {
                    res.push_back(std::make_pair(p.first, 0));
                }
                else if(mm.rbegin()->first != res.back().second)
                {
                    res.push_back(std::make_pair(p.first, mm.rbegin()->first));
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    const auto& r = s.getSkyline(a);
    for(const auto& p : r)
    {
        std::cout<<p.first<<" "<<p.second<<" | ";
    }
    std::cout<<std::endl;
}
