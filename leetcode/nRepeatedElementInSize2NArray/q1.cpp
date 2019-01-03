#include "header.h"

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> s;
        for(int i : A)
        {
            if(s.count(i)) return i;
            s.insert(i);
        }
        return -1;
    }
};

int main()
{
    Solution s;
}
