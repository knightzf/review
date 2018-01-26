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
    vector<vector<string>> groupStrings(vector<string>& strings) {
        std::unordered_map<std::string, vector<string>> m;
        for(const auto& s : strings)
        {
            m[toBase(s)].push_back(s);
        }

        vector<vector<string>> res;
        for(const auto& i : m)
        {
            res.push_back(i.second);
        }

        return res;
    }

    std::string toBase(const string& s)
    {
        string t = s;
        int diff = t[0] - 'a';
        for(int i = 0; i < t.size(); ++i)
        {
            t[i] = shift(t[i], diff);
        }

        return t;
    }

    char shift(char c, int n)
    {
        if(n == 0) return c;

        if(c - 'a' >= n)
        {
            return c - n;
        }
        else
        {
            return c + 26 - n;
        }
    }
};


int main() {
    Solution s;
}
