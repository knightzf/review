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
    string boldWords(vector<string>& words, string S) {
        std::unordered_map<int, std::unordered_set<std::string>> wordMap;
        for(const auto& w : words)
        {
            wordMap[w.size()].insert(w);
        }

        int n = S.size();
        std::string v(n, '0');

        for(int i = 0; i < n; ++i)
        {
            for(int j = 1; j <= n - i; ++j)
            {
                if(wordMap.find(j) != wordMap.end())
                {
                    const auto& temp = S.substr(i, j);
                    for(const auto& w : wordMap[j])
                    {
                        if(temp == w)
                        {
                            v.replace(v.begin() + i, v.begin() + i + j, j, '1');
                            break;
                        }
                    }
                }
            }
        }

        //std::cout<<"v "<<v<<std::endl;
        std::string res;
        for(int i = 0; i < n;)
        {
            if(v[i] == '0')
            {
                res += S[i];
                ++i;
            }
            else
            {
                int j = i;
                while(j < n)
                {
                    if(v[j] == '1')
                    {
                        ++j;
                    }
                    else
                    {
                        --j;
                        break;
                    }
                }
                res += "<b>" + S.substr(i, j - i + 1) + "</b>";
                i = j + 1;
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<string> a{"ab", "bc"};
    string b = "aabcd";
    s.boldWords(a, b);
}
