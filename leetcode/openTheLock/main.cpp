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

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target)
    {
        std::string start = "0000";

        std::unordered_set<std::string> deadendSet(deadends.begin(), deadends.end());

        if(deadendSet.find(start) != deadendSet.end())
        {
            return -1;
        }

        std::unordered_set<std::string> visited;

        std::queue<std::string> q;
        q.push(start);
        int count = 1;
        int level = 0;
        bool found = false;

        while(!q.empty())
        {
            for(int i = 0; i < count; ++i)
            {
                const auto& s = q.front();
                //std::cout<<s<<std::endl;
                if(s == target)
                {
                    found = true;
                    break;
                }

                visited.insert(s);
                q.pop();
                const auto& possV = nextPossibles(s, visited, deadendSet);
                //std::cout<<"size "<<possV.size()<<std::endl;
                for(const auto& s : possV)
                {
                    q.push(s);
                }
            }

            if(found)
            {
                return level;
            }

            count = q.size();
            ++level;
        }

        return -1;
    }

    std::vector<std::string> nextPossibles(const std::string& s,
                                           std::unordered_set<std::string>& visited,
                                           std::unordered_set<std::string>& deadendSet)
    {
        std::vector<std::string> res;

        int a = s[0] - '0';
        int b = s[1] - '0';
        int c = s[2] - '0';
        int d = s[3] - '0';

        std::vector<int> aV = { a == 0 ? 9 : a - 1, a == 9 ? 0 : a + 1};
        std::vector<int> bV = { b == 0 ? 9 : b - 1, b == 9 ? 0 : b + 1};
        std::vector<int> cV = { c == 0 ? 9 : c - 1, c == 9 ? 0 : c + 1};
        std::vector<int> dV = { d == 0 ? 9 : d - 1, d == 9 ? 0 : d + 1};

        for(int i = 0; i < 2; ++i)
        {
            std::stringstream ss;
            ss<< aV[i] << b << c << d;
            const auto& s = ss.str();
            if(visited.find(s) == visited.end() && deadendSet.find(s) == deadendSet.end())
            {
                visited.insert(s);
                res.push_back(s);
            }
        }

        for(int i = 0; i < 2; ++i)
        {
            std::stringstream ss;
            ss<< a << bV[i] << c << d;
            const auto& s = ss.str();
            if(visited.find(s) == visited.end() && deadendSet.find(s) == deadendSet.end())
            {
                visited.insert(s);
                res.push_back(s);
            }
        }

        for(int i = 0; i < 2; ++i)
        {
            std::stringstream ss;
            ss<< a << b << cV[i] << d;
            const auto& s = ss.str();
            if(visited.find(s) == visited.end() && deadendSet.find(s) == deadendSet.end())
            {
                visited.insert(s);
                res.push_back(s);
            }
        }

        for(int i = 0; i < 2; ++i)
        {
            std::stringstream ss;
            ss<< a << b << c << dV[i];
            const auto& s = ss.str();
            if(visited.find(s) == visited.end() && deadendSet.find(s) == deadendSet.end())
            {
                visited.insert(s);
                res.push_back(s);
            }
        }

        return res;
    }

};

int main()
{
    Solution s;
    //std::vector<std::string> d{"0201","0101","0102","1212","2002"};
    std::vector<std::string> d{"8887","8889","8878","8898","8788","8988","7888","9888"};
    std::cout<<s.openLock(d, "8888")<<std::endl;
}
