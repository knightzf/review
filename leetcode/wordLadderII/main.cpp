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

struct Word
{
    Word(const std::string& s) : str(s), prev(nullptr) {}
    std::string str;
    Word* prev;
};

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        vector<vector<string>> res;

        std::unordered_set<std::string> wordDict(wordList.begin(), wordList.end());

        std::queue<Word*> q;
        q.push(new Word(beginWord));

        int qsize = 1;
        int level = 1;
        int maxLevel = -1;

        while(!q.empty())
        {
            std::set<std::string> tempV;

            for(int i = 0; i < qsize; ++i)
            {
                const std::string& s = q.front()->str;

                const std::vector<std::string>& neighbors = nextWords(s, wordDict);

                if(maxLevel != -1 && level > maxLevel)
                {
                    q = std::queue<Word*>();
                    break;
                }

                for(const auto neighbor : neighbors)
                {
                    if(neighbor == endWord)
                    {
                        if(maxLevel == -1)
                        {
                            maxLevel = level;
                        }

                        std::vector<std::string> t;
                        Word* w = q.front();
                        while(w)
                        {
                            t.push_back(w->str);
                            w = w->prev;
                        }

                        std::reverse(t.begin(), t.end());
                        t.push_back(endWord);
                        res.emplace_back(t);
                    }
                    else
                    {
                        tempV.insert(neighbor);
                        Word* next = new Word(neighbor);
                        next->prev = q.front();
                        q.push(next);
                    }
                }

                q.pop();
            }

            for(const auto t : tempV)
            {
                wordDict.erase(t);
            }

            ++level;
            qsize = q.size();
        }

        return res;
    }

    std::vector<std::string> nextWords(const std::string& s, std::unordered_set<std::string>& wordDict)
    {
        std::vector<std::string> res;

        for(int i = 0; i < s.size(); ++i)
        {
            for(int j = 0; j < 26; ++j)
            {
                std::string t = s;
                t[i] = 'a' + j;
                if(t != s && wordDict.find(t) != wordDict.end())
                {
                    res.emplace_back(t);
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    //std::vector<std::string> v{"hot","dot","dog","lot","log","cog"};
    //const auto r = s.findLadders("hit", "cog", v);
    //std::vector<std::string> v{"a","b","c"};
    //const auto r = s.findLadders("a", "c", v);
    std::vector<std::string> v{"ted","tex","red","tax","tad","den","rex","pee"};
    const auto r = s.findLadders("red", "tax", v);
    std::cout<<r.size()<<std::endl;
}
