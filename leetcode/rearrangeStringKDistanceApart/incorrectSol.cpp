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

        int totalCnt = 26;
        for(int i = 0; i < 26; ++i)
        {
            if(v[i].second == 0)
            {
                totalCnt = i + 1;
                break;
            }
        }

        std::string res;
        int cnt = 0;
        std::unordered_map<char, int> m;
        while(cnt < s.size())
        {
            for(int i = 0; i < totalCnt; ++i)
            {
                if(v[i].second > 0)
                {
                    if(m.find(v[i].first) != m.end() && (res.size() - m[v[i].first] < k))
                    {
                        return "";
                    }

                    m[v[i].first] = res.size();
                    res += v[i].first;
                    --v[i].second;
                    ++cnt;
                }
            }
            /*int idx = 0;
            for(int i = 0; i < k; ++i)
            {
                while(v[idx].second == 0 && idx < totalCnt) ++idx;
                if(idx == totalCnt) return "";

                res += v[idx].first;
                --v[idx].second;
                ++cnt;
                ++idx;

                if(cnt == s.size()) break;
            }*/
        }

        return res;
    }
};

int main() {
    Solution s;
    std::cout<<s.rearrangeString("aabbcc", 2)<<std::endl;

}
