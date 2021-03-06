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

/*class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank)
    {
        if(start == end) return 0;

        if(bank.empty()) return -1;

        std::queue<std::string> q;
        q.push(start);
        int qsize = 1;
        int steps = 0;

        std::unordered_set<std::string> bankDict(bank.begin(), bank.end());
        std::unordered_set<std::string> visited;

        while(!q.empty())
        {
            for(int i = 0; i < qsize; ++i)
            {
                const auto& s = q.front();
                visited.insert(s);

                if(s == end)
                {
                    return steps;
                }

                std::vector<std::string> mutations;
                getMutations(s, bankDict, visited, mutations);

                if(mutations.empty())
                {
                    continue;
                }

                for(const auto& m : mutations)
                {
                    q.push(m);
                }

                q.pop();
            }

            qsize = q.size();
            ++steps;
        }

        return -1;
    }

    void getMutations(const std::string& gene,
                      const std::unordered_set<std::string>& bankDict,
                      std::unordered_set<std::string>& visited,
                      std::vector<std::string>& mutations)
    {
        static std::string t = "ACGT";

        std::string s = gene;

        for(int i = 0; i < 8; ++i)
        {
            char c = s[i];

            for(int j = 0; j < 4; ++j)
            {
                if(t[j] != c)
                {
                    s[i] = t[j];

                    if(bankDict.find(s) != bankDict.end() && visited.find(s) == visited.end())
                    {
                        visited.insert(s);
                        mutations.push_back(s);
                    }
                }
            }

            s[i] = c;
        }
    }
 };
*/

class Solution {
public:
    int reachNumber(int target)
    {
        std::queue<int> q;
        q.push(0);

        int qsize = q.size();
        int steps = 0;
        int stepSize = 1;

        while(qsize)
        {
            for(int i = 0; i < qsize; ++i)
            {
                int n = q.front();
                q.pop();

                if(n == target)
                {
                    return steps;
                }

                q.push(n - stepSize);
                q.push(n + stepSize);
            }

            ++stepSize;
            ++steps;
            qsize = q.size();
        }

        return -1;
    }
};
int main()
{
    Solution s;
    std::cout<<s.reachNumber(2)<<std::endl;
    //vector<string> a{"AATTCCGG","AACCTGGG","AACCCCGG","AACCTACC"};
    //std::cout<<s.minMutation("AACCTTGG", "AATTCCGG", a)<<std::endl;
}
