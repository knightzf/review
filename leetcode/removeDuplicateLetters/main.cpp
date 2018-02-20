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
    string removeDuplicateLetters(string s) {
        std::map<char, int> m;
        for(int i = 0; i < s.size(); ++i)
        {
            ++m[s[i]];
        }

        std::string uniq;
        for(const auto& p : m)
        {
            uniq += p.first;
        }

        std::unordered_map<char, std::map<int, vector<int>>> test;
        vector<int> temp(26, 0);
        for(int i = s.size() - 1; i >= 0; --i)
        {
            test[s[i]].emplace(i, temp);
            ++temp[s[i] - 'a'];
        }

        std::string res;
        int lastIdx = -1;
        while(!uniq.empty())
        {
            for(int i = 0; i < uniq.size(); ++i)
            {
                char c = uniq[i];
                std::string rest = uniq.substr(0, i - 0) + uniq.substr(i + 1);
                if(test.find(c) != test.end())
                {
                    bool ok = false;
                    for(const auto& p : test[c])
                    {
                        if(p.first > lastIdx)
                        {
                            bool good = true;
                            for(auto ch : rest)
                            {
                                if(p.second[ch - 'a'] == 0)
                                {
                                    good = false;
                                    break;
                                }
                            }

                            if(good)
                            {
                                res += c;
                                lastIdx = p.first;
                                ok = true;
                                break;
                            }
                        }
                    }

                    if(ok)
                    {
                        uniq = rest;
                        break;
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    std::cout<<s.removeDuplicateLetters("cbacdcbc")<<std::endl;
}
