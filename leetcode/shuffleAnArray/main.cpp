#include "header.h"

class Solution {
private:
    vector<int> v;
public:
    Solution(const vector<int>& nums) : v(nums) {

    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> t = v;
        int n = t.size();
        for(int i = 0; i < n; ++i)
        {
            int r = rand() % (n - i);
            std::swap(t[i], t[i + r]);
        }
        return t;
    }
};


int main()
{
    //Solution s;
}
