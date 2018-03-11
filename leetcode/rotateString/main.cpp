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
    bool rotateString(string A, string B) {
        if(A.size() != B.size()) return false;
        int n = A.size();
        if(n == 0) return true;

        for(int i = 0; i < n; ++i)
        {
            if(B[i] == A[0])
            {
                int j = i;
                int k = 0;
                while(B[j] == A[k] && k < n)
                {
                    j = nextIdx(j, n);
                    ++k;
                }

                if(k == n) return true;
            }
        }

        return false;
    }
private:
    int nextIdx(int i, int n)
    {
        if(i < n - 1) return i + 1;
        return 0;
    }
};

int main() {
    Solution s;
    std::cout<<s.rotateString("abcde", "cdeab")<<std::endl;
    std::cout<<s.rotateString("abcde", "abced")<<std::endl;

}
