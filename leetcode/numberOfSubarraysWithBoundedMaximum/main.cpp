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
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = A.size();
        int res = 0;

        bool found = false;
        int startIdx = 0;
        int lastIdxInRange = 0;
        for(int i = 0; i < n; ++i)
        {
            if(A[i] > R)
            {
                found = false;
                startIdx = i + 1;
                continue;
            }
            else
            {
                if(found == false && A[i] >= L && A[i] <= R)
                {
                    found = true;
                    lastIdxInRange = i;
                    res += i - startIdx + 1;

                }
                else if(found == true)
                {
                    if(A[i] >= L && A[i] <= R)
                    {
                        lastIdxInRange = i;
                        res += i - startIdx + 1;
                    }
                    else
                    {
                        res += lastIdxInRange - startIdx + 1;
                    }
                }
            }
        }

        return res;
    }
};


int main() {
    Solution s;
    vector<int> a{73,55,36,5,55,14,9,7,72,52};
    std::cout<<s.numSubarrayBoundedMax(a, 32, 69)<<std::endl;
}
