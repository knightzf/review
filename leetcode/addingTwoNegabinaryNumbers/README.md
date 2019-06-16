The hard point is to carry. If 1 + 1, it becomes 110. But 11 + 1 = 0.\
I solved the problem by handling this special case.\
Learned solution is smart because it sees the carry becomes -1. That's it.\
```C++
    vector<int> addNegabinary(vector<int>& A, vector<int>& B) {
        vector<int> res;
        int carry = 0, i = A.size() - 1, j = B.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) carry += A[i--];
            if (j >= 0) carry += B[j--];
            res.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        while (res.size() > 1 && res.back() == 0)
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
```