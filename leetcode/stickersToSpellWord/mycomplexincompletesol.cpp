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

using namespace std;

class Solution {
public:
    using WordIdxMap = std::map<int, std::pair<int, int>>;
    using WordMap = std::unordered_map<std::string, WordIdxMap>;

    using IdxElement = std::pair<int, std::pair<int, int>>;
    using IdxCombine = std::vector<IdxElement>;
    using IdxCombineVec = std::vector<IdxCombine>;

    int minStickers(vector<string>& stickers, string target)
    {
        WordMap wordMap;

        for(int i = 0; i < stickers.size(); ++i)
        {
            const std::string& sticker = stickers[i];
            int len = sticker.size();

            int wlen = 1;
            while(wlen <= len)
            {
                for(int j = 0; j < len - wlen + 1; ++j)
                {
                    const std::string& w = sticker.substr(j, wlen);
                    if(wordMap.find(w) == wordMap.end())
                    {
                        WordIdxMap wIdxMap;
                        wIdxMap.insert(std::make_pair(i, std::make_pair(j, wlen)));
                        wordMap.insert(std::make_pair(w, wIdxMap));
                    }
                    else
                    {
                        wordMap[w].insert(std::make_pair(i, std::make_pair(j, wlen)));
                    }

                }
                ++wlen;
            }
        }

        /*for(auto& item : wordMap)
        {
            std::cout<<item.first<<std::endl;
            for(auto& i : item.second)
            {
                std::cout<<"    "<<i.first<<": "<<i.second.first<<" "<< i.second.second<<std::endl;
            }
        }*/

        const std::vector<std::vector<std::string>>& possiComb = findAllComb(wordMap, target, 0);

        /*for(const auto& i : possiComb)
        {
            for(const auto& j : i)
            {
                std::cout<<j<<" ";
            }
            std::cout<<std::endl;
        }*/

        for(const auto& vec : possiComb)
        {
            std::vector<WordIdxMap> mapVec;
            for(const auto& w : vec)
            {
                mapVec.push_back(wordMap[w]);
            }

            auto r = getAllIdx(mapVec, 0);

            for(auto& m : r)
            {
                std::sort(m.begin(), m.end(), [](const IdxElement& a, const IdxElement& b){
                            return a.first < b.first;
                          });

                for(const auto& c : m)
                {
                    std::cout<<c.first<<": "<<c.second.first<<" "<<c.second.second<<
                        " "<< stickers[c.first].substr(c.second.first, c.second.second)<<std::endl;
                }
                std::cout<<"----"<<std::endl;

                std::cout<<"count "<<getCount(m)<<std::endl;
            }
        }
    }

private:

    bool isValid(vector<string>& stickers, const IdxCombine& com)
    {
        std::string w = stickers[com[0].first];
        for(int i = 0; i < com[0].second.second; ++i)
        {
            w[com[0].second.first + i] = '@';
        }

        for(int i = 1; i < com.size(); ++i)
        {
            if(com[i].first == com[i - 1].first)
            {
                for(int j = 0; j < com[i].second.second; ++j)
                {
                    if(w[com[i].second.first + j] == '@')
                    {
                        return false;
                    }
                    else
                    {
                        w[com[i].second.first + j] = '@';
                    }
                }
            }
            else
            {
                w = stickers[com[i].first];
            }
        }

        return true;
    }

    int getCount(const IdxCombine& com)
    {
        int count = 1;
        for(int i = 1; i < com.size(); ++i)
        {
            if(com[i].first != com[i - 1].first)
            {
                ++count;
            }
        }

        return count;
    }

    IdxCombineVec getAllIdx(const std::vector<WordIdxMap>& mapVec,
                            int startIdx)
    {
        IdxCombineVec result;

        if(startIdx == mapVec.size() - 1)
        {
            const auto& m = mapVec[startIdx];
            for(const auto& item : m)
            {
                IdxCombine c;
                c.push_back(std::make_pair(item.first, std::make_pair(item.second.first, item.second.second)));
                result.push_back(c);
            }
        }
        else
        {
            const auto& r = getAllIdx(mapVec, startIdx + 1);
            const auto& m = mapVec[startIdx];
            for(const auto& item : m)
            {
                for(const auto& res : r)
                {
                    IdxCombine c;
                    c.push_back(std::make_pair(item.first, std::make_pair(item.second.first, item.second.second)));
                    c.insert(c.end(), res.begin(), res.end());
                    result.push_back(c);
                }
            }
        }

        return result;
    }

    std::vector<std::vector<std::string>> findAllComb(const WordMap& wordMap,
                                                      const std::string& target,
                                                      int startIdx)
    {
        std::vector<std::vector<std::string>> result;

        if(startIdx == target.size() - 1)
        {
            const std::string& lastC = target.substr(startIdx, 1);
            if(wordMap.find(lastC) != wordMap.end())
            {
                result.push_back(std::vector<std::string>{lastC});
            }

            return result;
        }

        int maxLen = target.size() - startIdx;

        int len = 1;
        while(len < maxLen)
        {
            const std::string& w = target.substr(startIdx, len);
            if(wordMap.find(w) != wordMap.end())
            {
                const std::vector<std::vector<std::string>>& r = findAllComb(wordMap, target, startIdx + len);
                for(const auto& v : r)
                {
                    std::vector<std::string> t{w};
                    t.insert(t.end(), v.begin(), v.end());
                    result.push_back(t);
                }
            }

            ++len;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> stickers{"with", "example", "science"};
    sol.minStickers(stickers, "thehat");
    return 0;
}
