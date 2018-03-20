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
    string convertToTitle(int n) {
        string res;
        while(n != 0)
        {
            int t = n % 26;
            res = (t == 0 ? 'Z' : char('A' + t - 1)) + res;
            n = t == 0 ? n / 26 - 1 : n / 26;
        }
        return res;
    }
};

int main() {
    Solution s;
    std::cout<<s.convertToTitle(28)<<std::endl;
    std::cout<<s.convertToTitle(26)<<std::endl;
}
