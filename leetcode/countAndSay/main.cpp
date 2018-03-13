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
    string countAndSay(int n) {
        static std::vector<string> cache{"1"};
        if(n <= cache.size())
        {
            return cache[n - 1];
        }

        string temp;
        for(int i = cache.size(); i < n; ++i)
        {
            const auto& prev = cache.back();
            //std::cout<<prev<<std::endl;
            temp.clear();
            for(int j = 0; j < prev.size(); ++j)
            {
                int cnt = 1;
                while(j + 1 < prev.size() && prev[j] == prev[j + 1]) {
                    ++j;
                    ++cnt;
                }
                temp += std::to_string(cnt) + prev[j];

            }
            cache.push_back(temp);
        }

        return temp;
    }
};

int main() {
    Solution s;
    std::cout<<s.countAndSay(2)<<std::endl;
    std::cout<<s.countAndSay(5)<<std::endl;
}
