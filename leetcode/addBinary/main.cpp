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
#include <iterator>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()) a = std::string(b.size() - a.size(), '0') + a;
        else b = std::string(a.size() - b.size(), '0') + b;

        int extra = 0;
        for(int i = a.size() - 1; i >= 0; --i)
        {
            int t = a[i] - '0' + b[i] - '0' + extra;
            if(t >= 2) extra = 1;
            else extra = 0;

            if(t % 2 == 0)
                a[i] = '0';
            else
                a[i] = '1';
        }

        if(extra == 1) a = '1' + a;
        return a;
    }
};

int main() {
    Solution s;
    s.addBinary("0", "0");
}
