#include <iostream>
#include <vector>

using namespace std;

void init(vector<int>& bit, int n, int idx, int val)
{
    ++idx;
    while(idx <= n) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

int sum(const vector<int>& bit, int idx)
{
    ++idx;
    int res = 0;
    while(idx > 0) {
        res += bit[idx];
        idx -= (idx & -idx);
    }
    return res;
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5};
    int n = nums.size();
    vector<int> bit(n + 1, 0);

    for(int i = 0; i < n; ++i) {
        init(bit, n, i, nums[i]);
    }
}
