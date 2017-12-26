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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        std::unordered_set<std::string> wordDict(wordList.begin(), wordList.end());

        std::queue<std::string> q;
        q.push(beginWord);

        int dist = 1;
        int qsize = 1;

        while(!q.empty())
        {
            for(int i = 0; i < qsize; ++i)
            {
                const std::string& s = q.front();

                const std::vector<std::string>& neighbors = nextWords(s, wordDict);
                for(const auto neighbor : neighbors)
                {
                    if(neighbor == endWord)
                    {
                        return dist + 1;
                    }
                    else
                    {
                        q.push(neighbor);
                    }
                }

                q.pop();
            }

            qsize = q.size();
            ++dist;
        }

        return 0;
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
                    wordDict.erase(t);
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
    std::vector<std::string> v{"hot","dot","dog","lot","log","cog"};
    std::cout<<s.ladderLength("hit", "cog", v)<<std::endl;
}
