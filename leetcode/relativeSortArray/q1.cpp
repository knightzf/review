#include "header.h"

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        for(int i : arr1) ++m[i];
        int j = 0;
        for(int i : arr2) {
            while(m[i]--) arr1[j++] = i;
        }
        for(auto& p : m) {
            if(p.second > 0) {
                while(p.second--) arr1[j++] = p.first;
            }
        }
        return arr1;
    }
};


int main()
{
    Solution s;
}
