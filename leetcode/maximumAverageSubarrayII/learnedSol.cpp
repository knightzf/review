#include "header.h"

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double left = INT_MAX, right = INT_MIN;
        for(int i = 0; i < n; ++i)
        {
            left = min(left, (double)nums[i]);
            right = max(right, (double)nums[i]);
        }

        double prev = left;
        while(true)
        {
            double mid = (left + right) * 0.5;
            cout<<mid<<endl;
            if(valid(nums, k, mid))
            {
                //cout<<"valid "<<mid<<endl;
                if(abs(prev - mid) < 0.00001) return mid;
                left = mid;
                prev = mid;
            }
            else
            {
                right = mid;
            }
        }
    }

    bool valid(vector<int>& nums, int k, double avg)
    {
        double sum = 0;
        for(int i = 0; i < k; ++i)
        {
            sum += nums[i] - avg;
        }
        cout<<avg<<" "<<sum<<endl;
        if(sum >= 0) return true;

        double minsum = 0;
        double prevsum = 0;
        for(int i = k, n = nums.size(); i < n; ++i)
        {
            sum += nums[i] - avg;
            prevsum += nums[i - k] - avg;
            minsum = min(minsum, prevsum);
            if(sum - minsum >= 0) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    //vector<int> a{1,12,-5,-6,50,3};
    //cout<<s.findMaxAverage(a, 4)<<endl;
    vector<int> a{8,9,3,1,8,3,0,6,9,2};
    cout<<s.findMaxAverage(a, 8)<<endl;
}
