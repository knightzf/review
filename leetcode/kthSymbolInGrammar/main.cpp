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
    int kthGrammar(int N, int K) {
        int n = N - 1;
        int k = K - 1;
        if(n == 0) return 0;
        if(n == 1) return k == 0 ? 0 : 1;

        bool odd = k % 2 == 1;

        std::vector<int> s;
        s.push_back(k);
        while(n != 0)
        {
            k = k / 2;
            s.push_back(k);
            --n;
        }

        std::reverse(s.begin(), s.end());

        int res = 0;
        for(int i = 1; i < s.size(); ++i)
        {
            if(s[i] == s[i - 1] * 2)
            {
                res = res == 0 ? 0 : 1;
            }
            else
            {
                res = res == 0 ? 1 : 0;
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    std::cout<<s.kthGrammar(1, 1)<<std::endl;
    std::cout<<s.kthGrammar(2, 1)<<std::endl;
    std::cout<<s.kthGrammar(2, 2)<<std::endl;
    std::cout<<s.kthGrammar(4, 5)<<std::endl;
    std::cout<<s.kthGrammar(4, 3)<<std::endl;
}
