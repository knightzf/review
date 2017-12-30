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

using namespace std;

class Solution {
public:
    string toHex(int num)
    {
        if(num == 0) return "0";

        static std::unordered_map<int, char> m{
            {0, '0'},
            {1, '1'},
            {2, '2'},
            {3, '3'},
            {4, '4'},
            {5, '5'},
            {6, '6'},
            {7, '7'},
            {8, '8'},
            {9, '9'},
            {10, 'a'},
            {11, 'b'},
            {12, 'c'},
            {13, 'd'},
            {14, 'e'},
            {15, 'f'}};
        long a = num < 0 ? ((long)1 << 32) + num : num;

        //std::cout<<((long)1 << 32) - 1<<std::endl;
        //std::cout<<a<<std::endl;
        std::string s;
        while(a)
        {
            s += m[a % 16];
            a = a / 16;
        }

        std::reverse(s.begin(), s.end());

        return s;
    }
};

int main()
{
    Solution s;
    std::cout<<s.toHex(-1)<<std::endl;;
}
