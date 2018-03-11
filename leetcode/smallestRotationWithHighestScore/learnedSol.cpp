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
    int bestRotation(vector<int>& A) {
        int N = A.size();
        vector<int> change(N, 0);
        for(int i=0;i<N;++i)
        {
            change[(i - A[i] + 1 + N) % N] -= 1;
        }

        for(int i=1;i<N;++i) change[i] += change[i - 1] + 1;

        return distance(change.begin(), max_element(change.begin(), change.end()));
    }
};

int main() {
    Solution s;
    vector<int> a{2, 3, 1, 4, 0};
    //vector<int> a{1, 3, 0, 2, 4};
    std::cout<<s.bestRotation(a)<<std::endl;
}
