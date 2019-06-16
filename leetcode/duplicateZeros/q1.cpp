#include "header.h"

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> t; t.reserve(n);
        for(int i = 0; i < n && t.size() < n; ++i) {
            t.push_back(arr[i]);
            if(arr[i] == 0 && t.size() < n)            
                t.push_back(0);
        }
        arr = t;
    }
};

int main()
{
    Solution s;
}
