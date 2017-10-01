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
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        std::map<std::string, std::vector<std::string>> wordMap;

        for(const auto& word : strs)
        {
            std::string w(word);
            std::sort(w.begin(), w.end());

            auto iter = wordMap.find(w);
            if(iter == wordMap.end())
            {
                std::vector<std::string> t{word};
                wordMap.insert(std::make_pair(w, t));
            }
            else
            {
                iter->second.push_back(word);
            }
        }

        vector<vector<string>> result;
        for(const auto& item : wordMap)
        {
            result.push_back(item.second);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> a{"eat", "tea", "tan", "ate", "nat", "bat"};

    const auto& b = sol.groupAnagrams(a);

    for(const auto& i : b)
    {
        for(const auto& j : i)
        {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
