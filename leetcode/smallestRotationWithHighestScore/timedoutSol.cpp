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
        int n = A.size();
        if(n < 2) return 0;

        int maxScore = 0;
        int bestRotate = 0;
        for(int i = 0; i < n; ++i)
        {
            int score = 0;
            for(int j = 0; j < n; ++j)
            {
                int newIdx = indexAfterRotate(j, i, n);
                score += A[j] <= newIdx ? 1 : 0;
            }

            //std::cout<<i<<" "<<score<<std::endl;
            if(score > maxScore)
            {
                maxScore = score;
                bestRotate = i;
            }
        }

        return bestRotate;
    }

private:
    int indexAfterRotate(int i, int k, int n)
    {
        if(k == 0) return i;
        if(i >= k) return i - k;
        else return n + i - k;
    }
};

int main() {
    Solution s;
    //vector<int> a{2, 3, 1, 4, 0};
    vector<int> a{1, 3, 0, 2, 4};
    std::cout<<s.bestRotation(a)<<std::endl;
}
