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
    bool wordPatternMatch(string pattern, string str) {
        if(pattern.empty()) return str.empty();

        std::unordered_map<string, char> strMap;
        std::unordered_map<char, string> charMap;
        return impl(pattern, str, 0, 0, pattern.size(), str.size(), strMap, charMap);
    }

    bool impl(const std::string& pattern, const std::string& str, int pIdx, int sIdx, int pSize, int sSize,
              std::unordered_map<string, char>& strMap,
              std::unordered_map<char, string>& charMap)
    {
        //std::cout<<pIdx<<" "<<pSize<<" "<<sIdx<<" "<<sSize<<std::endl;
        if(pIdx == pSize && sIdx == sSize) return true;
        if(pIdx == pSize || sIdx == sSize) return false;

        for(int i = sIdx; i < sSize; ++i)
        {
            const auto& s = str.substr(sIdx, i - sIdx + 1);
            char c = pattern[pIdx];

            bool flag = false;
            //if(sIdx == 3)
            //std::cout<<s<<" "<<c<<" "<<pIdx<<std::endl;

            if(strMap.find(s) == strMap.end() && charMap.find(c) == charMap.end())
            {
                strMap[s] = c;
                charMap[c] = s;
                //std::cout<<"s "<<s<<" "<<c<<std::endl;
                bool r = impl(pattern, str, pIdx + 1, i + 1, pSize, sSize, strMap, charMap);
                flag = flag || r;
                if(r) return true;
                strMap.erase(s);
                charMap.erase(c);
            }
            else if(strMap.find(s) == strMap.end() || charMap.find(c) == charMap.end())
            {
                flag = flag || false;
            }
            else if(strMap[s] == c && charMap[c] == s)
            {
                //std::cout<<"s1 "<<s<<" "<<c<<std::endl;
                flag = flag || impl(pattern, str, pIdx + 1, i + 1, pSize, sSize, strMap, charMap);
            }
            else
            {
                flag = flag || false;
            }

            if(flag) return true;
        }

        return false;
    }
};

int main() {
    Solution s;
    std::cout<<s.wordPatternMatch("aa", "cdcd")<<std::endl;
    std::cout<<s.wordPatternMatch("abab", "redblueredblue")<<std::endl;
    std::cout<<s.wordPatternMatch("aaaa", "asdasdasdasd")<<std::endl;
    std::cout<<s.wordPatternMatch("aabb", "xyzabcxzyabc")<<std::endl;
}
