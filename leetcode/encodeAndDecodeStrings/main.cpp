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

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for(const auto& s : strs)
        {
            for(char c : s)
            {
                res += charToNumStr(c);
            }
            res += ",";
        }

        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        std::string t;
        for(int i = 0; i < s.size();)
        {
            if(std::isdigit(s[i]))
            {
                t += char(std::stoi(s.substr(i, 3)));
                i += 3;
            }
            else
            {
                res.push_back(t);
                t.clear();
                ++i;
            }
        }

        return res;
    }

private:
    std::string charToNumStr(char c)
    {
        std::string t = std::to_string(int(c));
        if(t.size() < 3)
        {
            t = std::string(3 - t.size(), '0') + t;
        }

        return t;
    }
};

int main() {
    //Solution s;
}
