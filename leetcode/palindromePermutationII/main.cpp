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
    vector<string> generatePalindromes(string s) {
        int n = s.size();
        if(n < 2) return {s};

        vector<string> res;

        std::map<char, int> m;
        for(auto c : s)
        {
            ++m[c];
        }

        char oddChar = 0;

        if(n % 2 == 0)
        {
            for(const auto& p : m)
            {
                if(p.second % 2 != 0) return res;
            }
        }
        else
        {
            for(const auto& p : m)
            {
                if(p.second % 2 != 0)
                {
                    if(oddChar != 0) return res;
                    oddChar = p.first;
                }
            }
        }

        std::string str;
        for(auto& p : m)
        {
            str += std::string(p.second / 2, p.first);
        }

        //std::cout<<str<<std::endl;

        getPermutations(str, 0, str.size() - 1, res);
        /*for(auto i : res)
        {
            std::cout<<i<<std::endl;
        }*/
        for(int i = 0; i < res.size(); ++i)
        {
            string t = res[i]; std::reverse(t.begin(), t.end());
            if(oddChar != 0) res[i] += oddChar;
            res[i] += t;
        }

        /*
        for(auto i : res)
        {
            std::cout<<i<<std::endl;
        }
        */
        return res;
    }

    void getPermutations(std::string& s, int l, int r, vector<string>& res)
    {
        if(l == r)
        {
            res.push_back(s);
        }
        else
        {
            for(int i = l; i <= r; ++i)
            {
                if(i == l || (s[i] != s[l] && s[i] != s[i - 1]))
                {
                    swap(s[l], s[i]);
                    getPermutations(s, l + 1, r, res);
                    swap(s[l], s[i]);
                }
            }
        }
    }
};


int main() {
    Solution s;
    s.generatePalindromes("aaaabbbbcccc");
}
