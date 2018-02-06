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
private:
    std::unordered_set<string> visited;
public:
    bool canTransform(string start, string end) {
        visited.clear();
        int n = start.size();
        std::vector<std::pair<int, int>> v;
        for(int i = 0; i < n - 1; ++i)
        {
            if(start[i] == 'X' && start[i + 1] == 'L' )
            {
                v.push_back(std::make_pair(i, 0));
            }
            else if(start[i] == 'R' && start[i + 1] == 'X' )
            {
                v.push_back(std::make_pair(i, 1));
            }
        }

        return impl(start, end, v, 0);
    }

    bool impl(string& start, const std::string& end, std::vector<std::pair<int, int>>& v, int startIdx)
    {
        std::cout<<start<<" "<<v.size()<<" "<<startIdx<<std::endl;

        if(start == end) return true;

        visited.insert(start);

        for(int i = startIdx; i < v.size(); ++i)
        {
            auto& p = v[i];
            if((p.second == 0 && start[p.first] == 'X') || (p.second == 1 && start[p.first] == 'R'))
            {
                std::swap(start[p.first], start[p.first + 1]);
                if(visited.find(start) == visited.end())
                {
                    if(p.first + 2 < start.size() &&
                        (
                            (p.second == 0 && start[p.first + 2] == 'L') ||
                            (p.second == 1 && start[p.first + 2] == 'X')
                        )
                       )
                    {
                        p.first += 1;
                        if(impl(start, end, v, i)) return true;
                        p.first -= 1;
                    }
                    else if(p.first >= 1 &&
                            (
                                (p.second == 0 &&  start[p.first - 1] == 'X') ||
                                (p.second == 1 &&  start[p.first - 1] == 'R')
                            )
                            )
                    {
                        p.first -= 1;
                        if(impl(start, end, v, i)) return true;
                        p.first += 1;
                    }
                    else
                    {
                        if(impl(start, end, v, i + 1)) return true;
                    }
                }
                std::swap(start[p.first], start[p.first + 1]);
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    //std::cout<<s.canTransform("RXXLRXRXL", "XRLXXRRLX")<<std::endl;
    //std::cout<<s.canTransform("XXXXXLXXXX", "LXXXXXXXXX")<<std::endl;
    //std::cout<<s.canTransform("XXXXRXXXLX", "XXXXRLXXXX")<<std::endl;
    std::cout<<s.canTransform("XLXRRXXRXX", "LXXXXXXRRR")<<std::endl;
}
