#include "header.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n = digits.size();
        for(int i = n - 1; i >= 0; --i) {
            int t = digits[i] + carry;
            if(t >= 10) {
                digits[i] = t - 10;
                carry = 1;
            } else {
                digits[i] = t;
                carry = 0;
                break;
            }
        }
        if(carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};


int main()
{
    Solution s;
    
}