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

class WordFilter {
public:
    WordFilter(vector<string> words)
    {
        for(int i = 0; i < words.size(); ++i)
        {
            const auto& w = words[i];
            for(int j = 1; j <= w.size(); ++j)
            {
                const auto& prefix = w.substr(0, j);
                //std::cout<<"pre "<<prefix<<std::endl;
                if(prefixMap.find(prefix) == prefixMap.end())
                {
                    prefixMap[prefix] = std::set<int>{i};
                }
                else
                {
                    prefixMap[prefix].insert(i);
                }
            }

            for(int j = 0; j < w.size(); ++j)
            {
                const auto& posfix = w.substr(j, w.size() - j);
                //std::cout<<"ps "<<posfix<<std::endl;
                if(posfixMap.find(posfix) == posfixMap.end())
                {
                    posfixMap[posfix] = std::set<int>{i};
                }
                else
                {
                    posfixMap[posfix].insert(i);
                }
            }
        }

        mwords = std::move(words);
    }

    int f(string prefix, string suffix)
    {
        if(prefix.empty() && suffix.empty())
        {
            return mwords.size();
        }

        if(prefix.empty() && !suffix.empty())
        {
            if(posfixMap.find(suffix) == posfixMap.end())
            {
                return -1;
            }
            else
            {
                const auto& t = posfixMap[suffix];
                return *t.rbegin();
            }
        }

        if(!prefix.empty() && suffix.empty())
        {
            if(prefixMap.find(prefix) == prefixMap.end())
            {
                return -1;
            }
            else
            {
                const auto& t = prefixMap[prefix];
                return *t.rbegin();
            }
        }

        if( prefixMap.find(prefix) == prefixMap.end() ||
            posfixMap.find(suffix) == posfixMap.end())
        {
            return -1;
        }

        std::set<int> resSet;

        const auto& t1 = prefixMap[prefix];
        const auto& t2 = posfixMap[suffix];

        auto iter1 = t1.rbegin();
        auto iter2 = t2.rbegin();

        while(iter1 != iter2 && iter1 != t1.rend() && iter2 != t2.rend())
        {
            if(*iter1 == *iter2)
            {
                return *iter1;
            }
            else if(*iter1 > *iter2)
            {
                ++iter1;
            }
            else
            {
                ++iter2;
            }
        }

        /*std::set_intersection(t1.begin(), t1.end(), t2.begin(), t2.end(),
                              std::inserter(resSet, resSet.begin()));

        for(auto iter = resSet.rbegin(); iter != resSet.rend(); ++iter)
        {
            auto w = mwords[*iter];
            w.erase(0, prefix.size());
            if(w.size() > suffix.size() && w.substr(w.size() - suffix.size() - 1, suffix.size()) == suffix)
            {
                return *iter;
            }
        }*/

        return -1;

    }

private:
    std::unordered_map<std::string, std::set<int>> prefixMap;
    std::unordered_map<std::string, std::set<int>> posfixMap;
    vector<string> mwords;
};

int main()
{
    //Solution s;
    std::vector<std::string> a{"apple"};
    WordFilter w(a);
    std::cout<<w.f("a", "e")<<std::endl;
    std::cout<<w.f("b", "")<<std::endl;
}
