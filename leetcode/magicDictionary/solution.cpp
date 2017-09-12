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

using namespace std;

class MagicDictionary {
public:
    MagicDictionary()
    {
    }

    void buildDict(vector<string> dict)
    {
        for(const auto& word : dict)
        {
            auto iter = data.find(word.size());
            if(iter != data.end())
            {
                iter->second.push_back(word);
            }
            else
            {
                data.insert(std::make_pair(word.size(), std::vector<std::string>{word}));
            }
        }
    }

    bool search(string word)
    {
        auto iter = data.find(word.size());
        if(iter == data.end())
        {
            return false;
        }

        const auto& list = iter->second;
        for(const auto& key : list)
        {
            if(diffOne(key, word))
            {
                return true;
            }
        }

        return false;
    }

private:
    std::map<size_t, std::vector<std::string>> data;

    bool diffOne(const std::string& key, const std::string& word)
    {
        int diffCount = 0;
        for(size_t i = 0, sz = key.size(); i < sz; ++i)
        {
            if(key[i] != word[i])
            {
                ++diffCount;
            }

            if(diffCount > 1)
                return false;
        }

        return diffCount == 1;
    }
};
int main()
{
    //Solution sol;
    MagicDictionary d;
    d.buildDict(std::vector<std::string>{"hello", "leetcode"});
    std::cout<<d.search("hello")<<std::endl;
    std::cout<<d.search("hhllo")<<std::endl;
    std::cout<<d.search("hell")<<std::endl;
    std::cout<<d.search("leetcoded")<<std::endl;
    return 0;
}
