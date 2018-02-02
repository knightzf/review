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
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0) return 0;
        if(n == 1) return citations[0] == 0 ? 0 : 1;

        for(int i = n - 1; i >= 0; --i)
        {
            int c = citations[i];
            if(n - i == c)
            {
                return c;
            }
            else if(n - i > c)
            {
                if(i == n - 1) return 0;
                else
                {
                    for(int j = citations[i + 1]; j >= citations[i]; --j)
                    {
                        if(j == n - i - 1) return j;
                    }
                }
            }
            else if(n - i < c && i == 0)
            {
                return n;
            }
        }

        return 0;
    }
};

int main() {
    Solution s;
    //vector<int> a{4, 0, 6, 1, 5};
    //vector<int> a{7, 8, 9};
    vector<int> a{1, 2};
    std::cout<<s.hIndex(a)<<std::endl;
}
