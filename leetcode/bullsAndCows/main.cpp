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
    string getHint(string secret, string guess) {
        std::unordered_map<char, int> m;
        int bulls = 0, cows = 0;
        for(int i = 0; i < secret.size(); ++i)
        {
            if(secret[i] == guess[i])
            {
                ++bulls;
            }
            else
            {
                ++m[secret[i]];
            }
        }

        for(int i = 0; i < guess.size(); ++i)
        {
            if(secret[i] != guess[i])
            {
                char c = guess[i];
                auto iter = m.find(c);
                if(iter != m.end() && iter->second > 0)
                {
                    ++cows;
                    --iter->second;
                }
            }
        }

        return std::to_string(bulls) + 'A' + std::to_string(cows) + 'B';
    }
};

int main() {
    Solution s;
    std::cout<<s.getHint("1807", "7810")<<std::endl;
    std::cout<<s.getHint("1123", "0111")<<std::endl;
}
