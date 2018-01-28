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
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        if(n <= 2) return true;

        std::vector<bool> v(5000, false);
        int lastIdx = -1;

        for(int i = 0; i < n - 1;)
        {
            if(A[i] > A[i + 1])
            {
                //std::cout<<A[i] << " "<<A[i + 1] << " "<<lastIdx<<std::endl;
                if(A[i] - A[i + 1] != 1) return false;
                if(lastIdx != A[i + 1] - 1) return false;
                v[A[i]] = true;
                v[A[i + 1]] = true;
                lastIdx = A[i];
                i += 2;
            }
            else
            {
                if(lastIdx != A[i] - 1) return false;
                lastIdx = A[i];
                v[A[i]] = true;
                ++i;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    vector<int> a{1, 0, 2};
    vector<int> b{1, 2, 0};
    vector<int> c{1, 2, 0};
    vector<int> d{1, 0, 3, 2};
    vector<int> e{1, 3, 2, 0};
    std::cout<<s.isIdealPermutation(a)<<std::endl;
    std::cout<<s.isIdealPermutation(b)<<std::endl;
    std::cout<<s.isIdealPermutation(c)<<std::endl;
    std::cout<<s.isIdealPermutation(d)<<std::endl;
    std::cout<<s.isIdealPermutation(e)<<std::endl;
}
