#include "header.h"

class Monoqueue
{
private:
    deque<pair<int, int>> q;
public:
    void push(int val) {
        int count = 0;
        while(!q.empty() && q.back().first < val) {
            count += q.back().second + 1;
            q.pop_back();
        }
        q.push_back(make_pair(val, count));
    }

    int max() {
        return q.front().first;
    }

    void pop() {
        if(q.front().second--) {
            return;
        }
        q.pop_front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Monoqueue q;
        vector<int> res;
        for(int i = 0, n = nums.size(); i < n; ++i) {
            q.push(nums[i]);
            if(i > k - 1) {
                q.pop();
                res.push_back(q.max());
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}