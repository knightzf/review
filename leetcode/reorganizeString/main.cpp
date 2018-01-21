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
public:
    string reorganizeString(string S) {
        int n = S.size();
        if(n < 2) return S;

        std::unordered_map<char, int> m;
        for(int i = 0; i < n; ++i)
        {
            ++m[S[i]];
        }

        int maxCount = 0;
        char maxChar;
        for(auto& p : m)
        {
            if(p.second > maxCount)
            {
                maxCount = p.second;
                maxChar = p.first;
            }
        }

        if(maxCount - 1 > n - maxCount) return "";

        std::string res;
        bool flag = false;


        for(auto& p : m)
        {
            if(p.first != maxChar)
            {
                int count = 0;
                for(int i = 0; i < p.second; ++i)
                {
                    if(maxCount)
                    {
                        res += std::string(1, maxChar) + p.first;;
                        --maxCount;
                        ++count;
                    }
                    else
                    {
                        break;
                    }
                }

                p.second -= count;
            }
        }

        if(maxCount) res += maxChar;

        for(auto& p : m)
        {
            if(p.first != maxChar && p.second > 0)
            {
                string temp;

                for(int i = 0; i < p.second; ++i)
                {
                    temp += std::string(1, res[i]) + p.first;
                }

                res = temp + res.substr(p.second);
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    std::cout<<s.reorganizeString("aab")<<std::endl;
    std::cout<<s.reorganizeString("aaab")<<std::endl;
    std::cout<<s.reorganizeString("vvvlo")<<std::endl;
    std::cout<<s.reorganizeString("bfrbs")<<std::endl;
    std::cout<<s.reorganizeString("baaba")<<std::endl;
}
