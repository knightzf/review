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
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = getDepth(nestedList);
        int res = 0;
        calc(nestedList, depth, res);
        return res;
    }
    void calc(const vector<NestedInteger>& nestedList, int depth, int& res)
    {
        for(const auto& integer : nestedList)
        {
            if(integer.isInteger())
            {
                res += integer.getInteger() * depth;
            }
            else
            {
                calc(integer.getList(), depth - 1, res);
            }
        }
    }
    int getDepth(const vector<NestedInteger>& nestedList)
    {
        int t = 1;
        for(const auto& integer : nestedList)
        {
            if(!integer.isInteger())
            {
                int r = getDepth(integer.getList());
                t = max(t, r + 1);
            }
        }
        return t;
    }
};

int main() {
    Solution s;
}
