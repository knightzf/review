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
    string rearrangeString(string s, int k) {
        if(k < 2) return s;

        std::vector<std::pair<char, int>> v(26);
        for(int i = 0; i < s.size(); ++i)
        {
            v[s[i] - 'a'].first = s[i];
            ++v[s[i] - 'a'].second;
        }

        std::sort(v.begin(), v.end(), [](const std::pair<char, int>& a, const std::pair<char, int>& b){
                    if(a.second == b.second) return a.first < b.first;
                    return a.second > b.second;
                  });

        std::vector<std::string> strV(v[0].second);
        int equalIdx = 0;
        while(v[equalIdx].second == v[0].second) ++equalIdx;
        for(int i = 0; i < strV.size(); ++i)
        {
            for(int j = 0; j < equalIdx; ++j)
                strV[i] += v[j].first;
        }

        int rowIdx = 0;
        for(int vIdx = equalIdx; vIdx < 26; ++vIdx)
        {
            if(v[vIdx].second == 0) break;
            for(int j = 0; j < v[vIdx].second; ++j)
            {
                strV[rowIdx] += v[vIdx].first;
                if(rowIdx == strV.size() - 2)
                {
                    rowIdx = 0;
                }
                else
                {
                    ++rowIdx;
                }
            }
        }

        string res;
        for(int i = 0; i < strV.size(); ++i)
        {
            if(i != strV.size() - 1 && strV[i].size() < k) return "";
            res += strV[i];
        }

        if(res.size() > s.size()) return "";

        return res;
    }
};

int main() {
    Solution s;
    //std::cout<<s.rearrangeString("aabbcc", 2)<<std::endl;
    std::cout<<s.rearrangeString("aaabc", 2)<<std::endl;

}
