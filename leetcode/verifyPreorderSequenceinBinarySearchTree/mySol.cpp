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
    bool verifyPreorder(vector<int>& preorder) {
        return impl(preorder, 0, preorder.size());
    }

    bool impl(vector<int>& preorder, int start, int end)
    {
        if(end - start <= 2) return true;

        int mid = preorder[start];
        for(int i = start + 1; i < end; ++i)
        {
            if(preorder[i] > mid)
            {
                for(int j = i + 1; j < end; ++j)
                {
                    if(preorder[j] < mid) return false;
                }

                return impl(preorder, start + 1, i) && impl(preorder, i, end);
            }
        }

        return impl(preorder, start + 1, end);
    }
};


int main() {
    Solution s;
}
