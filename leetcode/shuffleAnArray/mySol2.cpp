#include "header.h"

class Solution {
private:
    const vector<int>& m_nums;
public:
    Solution(vector<int>& nums) : m_nums(nums) {

    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return m_nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = m_nums;
        for(int i = 0, n = res.size(); i < n; ++i) {
            int idx = rand() % (n - i);
            swap(res[idx], res[n - i - 1]);
        }
        return res;
    }
};

int main()
{
    //Solution s;
}