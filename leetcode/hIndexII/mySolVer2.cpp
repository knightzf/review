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
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0) return 0;

        int i = 0, j = n;
        while(i < j)
        {
            int m = (i + j) / 2;
            if(citations[m] < n - m)
            {
                i = m + 1;
            }
            else if(citations[m] > n - m)
            {
                j = m;
            }
            else
            {
                return citations[m];
            }
        }

        return n - j;
    }
};

int main() {
    Solution s;
    vector<int> a{0, 1, 3, 5, 6};
    //vector<int> a{1};
    std::cout<<s.hIndex(a)<<std::endl;
}
