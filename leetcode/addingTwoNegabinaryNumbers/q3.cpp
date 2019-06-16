#include "header.h"

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        if(arr1.size() < arr2.size()) swap(arr1, arr2);
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        for(int i = 0, n = min(arr1.size(), arr2.size()); i < n; ++i) {
            arr1[i] += arr2[i]; 
        }
        for(int i = 0; i < arr1.size(); ++i) {
            if(arr1[i] < 2) continue;
            while(arr1[i] >= 2) {
                arr1[i] -= 2;
                if(i < arr1.size() - 1 && arr1[i + 1]) arr1[i + 1] -= 1;
                else {
                    if(i + 1 >= arr1.size()) arr1.push_back(0);
                    arr1[i + 1] += 1;
                    if(i + 2 >= arr1.size()) arr1.push_back(0);
                    arr1[i + 2] += 1;
                }
            }
        }
        while(arr1.size() > 1 && arr1.back() == 0) arr1.pop_back();
        reverse(arr1.begin(), arr1.end());
        return arr1;
    }
};

int main()
{
    Solution s;
}

