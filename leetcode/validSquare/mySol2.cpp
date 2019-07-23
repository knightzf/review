#include "header.h"

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> s{d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4)};
        return !s.count(0) && s.size() == 2;
    }

    int d(const vector<int>& a, const vector<int>& b) {
        return pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2);
    }
};

int main()
{
    Solution s;
}