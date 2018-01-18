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

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        using Event = std::pair<int, int>; // x h pair

        std::vector<Event> events;
        for(const auto& v : buildings)
        {
            events.emplace_back(v[0], v[2]);
            events.emplace_back(v[1], -v[2]);
        }

        std::sort(events.begin(), events.end(), [](const Event&a, const Event& b){
                    if(a.first == b.first) return a.second > b.second;
                    return a.first < b.first;
                  });

        std::multiset<int> heights;
        vector<pair<int, int>> res;

        for(const auto& event : events)
        {
            int x = event.first;
            bool entering = event.second > 0;
            int height = std::abs(event.second);

            if(entering)
            {
                if(height > getMax(heights))
                {
                    res.emplace_back(x, height);
                }
                heights.insert(height);
            }
            else
            {
                heights.erase(heights.find(height));
                //std::cout<<(heights.equal_range(height).first == heights.end())<<std::endl;
                //heights.erase(heights.equal_range(height).first);
                std::cout<<heights.size()<<std::endl;
                if(height > getMax(heights))
                {
                    res.emplace_back(x, getMax(heights));
                }
            }
        }

        return res;
    }

private:
    int getMax(const std::multiset<int>& set)
    {
        if(set.empty()) return 0;
        return *set.rbegin();
    }
};

int main() {
    Solution s;
    vector<vector<int>> a{ {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8} };
    const auto& b = s.getSkyline(a);
    for(const auto& p : b)
    {
        std::cout<<p.first<<" "<<p.second<<"|";
    }
    std::cout<<std::endl;
}
