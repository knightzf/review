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
    string customSortString(string S, string T) {
        std::unordered_map<char, int> m;
        for(int i = 0; i < S.size(); ++i)
        {
            m[S[i]] = i;
        }

        std::string t;
        std::string b;
        for(int i = 0; i < T.size(); ++i)
        {
            char c = T[i];
            if(m.find(c) != m.end())
            {
                t += c;
            }
            else
            {
                b += c;
            }
        }

        std::sort(t.begin(), t.end(), [&](const char& a, const char& b){
                        return m[a] < m[b];
                  });
        return t + b;
    }
};

int main() {
    Solution s;
    std::cout<<s.customSortString("exv", "xwvee")<<std::endl;
    //std::cout<<s.customSortString("cba", "abcd")<<std::endl;
    //std::cout<<s.customSortString("hucw", "utzoampdgkalexslxoqfkdjoczajxtuhqyxvlfatmptqdsochtdzgypsfkgqwbgqbcamdqnqztaqhqanirikahtmalzqjjxtqfnh")<<std::endl;
}
