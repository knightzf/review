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
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        if(n == 0) return 0;

        std::sort(answers.begin(), answers.end());

        int total = 0;

        for(int i = 0; i < n;)
        {
            int m = answers[i];
            total += m + 1;
            int count = 0;
            while(answers[i] == m && i < n && count < m + 1)
            {
                ++i;
                ++count;
            }
        }

        return total;
    }
};

int main() {
    Solution s;
}
