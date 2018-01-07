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
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n, 0);

        std::map<int, int> bMap;
        for(int i = 0; i < n; ++i)
        {
            bMap.insert(std::make_pair(B[i], i));
        }

        for(int i = 0; i < n; ++i)
        {
            res[i] = bMap[A[i]];
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> A{12, 28, 46, 32, 50};
    vector<int> B{50, 12, 32, 46, 28};
    auto r = s.anagramMappings(A, B);
    for(auto i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
