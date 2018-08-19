#include "header.h"

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = 0;
        int sumB = 0;
        unordered_set<int> m;

        for(auto i : A)
            sumA += i;
        for(auto i : B) {
            sumB += i;
            m.insert(i);
        }

        int diff = (sumA + sumB) / 2 - sumB;
        for(int i : A)
        {
            if(m.count(i - diff))
            {
                return {i, i - diff};
            }
        }

        return {};
    }
};


int main()
{
    Solution s;
}
