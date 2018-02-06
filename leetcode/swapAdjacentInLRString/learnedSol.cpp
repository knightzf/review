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
    bool canTransform(string start, string end) {
        string a = start;
        string b = end;
        a.erase(std::remove_if(a.begin(), a.end(), [](char c){ return c == 'X';}), a.end());
        b.erase(std::remove_if(b.begin(), b.end(), [](char c){ return c == 'X';}), b.end());

        //std::cout<<a<<" "<<b<<std::endl;

        if(a != b) return false;

        int i = 0, j = 0;

        int n = start.size();
        while(i < n && j < n)
        {
            while(i < n && start[i] == 'X') ++i;
            while(j < n && end[j] == 'X') ++j;

            if(i == n && j == n) return true;

            if(i == n || j == n) return false;

            if(start[i] != end[j]) return false;

            char c = start[i];

            if(c == 'L' && j > i) return false;
            if(c == 'R' && i > j) return false;

            ++i;
            ++j;
        }

        return true;
    }
};

int main() {
    Solution s;
    //std::cout<<s.canTransform("RXXLRXRXL", "XRLXXRRLX")<<std::endl;
    //std::cout<<s.canTransform("XXXXXLXXXX", "LXXXXXXXXX")<<std::endl;
    //std::cout<<s.canTransform("XXXXRXXXLX", "XXXXRLXXXX")<<std::endl;
    std::cout<<s.canTransform("XLXRRXXRXX", "LXXXXXXRRR")<<std::endl;
}
