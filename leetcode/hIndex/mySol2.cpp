#include "header.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int res = 0;
        for(int i = 0, n = citations.size(); i < n; ++i) {
            res = max(res, min(citations[i], i + 1));
        }
        return res;
    }
};

int main()
{
    //Solution s;
}