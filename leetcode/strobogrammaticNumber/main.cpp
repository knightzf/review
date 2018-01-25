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
    bool isStrobogrammatic(string num) {
        int n = num.size();
        if(n == 0) return false;
        if(n == 1) return num[0] == '0' || num[0] == '1' || num[0] == '8';

        int i = 0, j = n - 1;
        while(i < j)
        {
            if(j == n - 1 && num[j] == '0') return false;

            if(!areStrobo(num[i], num[j])) return false;

            ++i;
            --j;
        }

        if(i == j)
        {
            return num[i] == '0' || num[i] == '1' || num[i] == '8';
        }
        else
        {
            return true;
        }
    }

private:
    bool areStrobo(char a, char b)
    {
        switch(a)
        {
        case '0':
        case '1':
        case '8':
            return b == a;
        case '6':
            return b == '9';
        case '9':
            return b == '6';
        }

        return false;
    }
};

int main() {
    Solution s;
}
