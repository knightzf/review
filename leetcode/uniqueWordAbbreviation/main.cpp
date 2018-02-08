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

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for(const auto& w : dictionary)
        {
            if(w.size() <= 2)
            {
                m[w].insert(w);
            }
            else
            {
                std::string t = w[0] + std::to_string(w.size() - 2) + w.back();
                m[t].insert(w);
            }
        }
    }

    bool isUnique(string word) {
        if(word.size() <= 2)
        {
            return true;
        }

        std::string key = word[0] + std::to_string(word.size() - 2) + word.back();
        if(m.find(key) == m.end()) return true;

        if(m[key].size() > 1) return false;

        return m[key].find(word) != m[key].end();
    }
private:
    std::unordered_map<string, std::unordered_set<string>> m;
};


int main() {
    //Solution s;
}
