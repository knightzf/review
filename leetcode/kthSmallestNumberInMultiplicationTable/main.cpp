#include "header.h"

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        if(m > n) swap(m, n);
        int low = 1, high = m * n;
        int prevNum = -1;
        while(true)
        {
            int mid = (low + high) / 2;
            int startIdx = bsearch(n, m * n, n, mid);
            int endIdx = bsearch(1, m, 1, mid);
            int cnt = (m - 1 - endIdx) * n;
            for(int i = startIdx; i <= endIdx; ++i) {
                int idx = bsearch(i + 1, (i + 1) * n, i + 1, mid);
                cnt += n - idx;
                if((i + 1) * (idx + 1) == mid) --cnt;
            }

            if(low == high ) {
                if(cnt > m * n - k) return prevNum;
                return mid;
            }

            if(mid != prevNum) {
                prevNum = mid;
            }

            if(cnt == m * n - k) {
                high = mid;
            }
            else if(cnt > m * n - k) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
    }

    int bsearch(int min, int max, int step, int target)
    {
        if(target >= max) return (max - min) / step;
        if(target <= min) return 0;
        int t = target / step;
        if(target % step == 0) return t - 1;
        return t;
    }

    int bsearch2(int min, int max, int step, int target)
    {   
        int n = (max - min) / step + 1;
        int low = 0, high = n - 1;
        while(low != high) {
            int mid = (low + high) / 2;
            int t = min + mid * step;
            if(t >= target) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution s;
    /*cout<<s.bsearch(1, 4, 1, 3)<<endl;
    cout<<s.bsearch2(1, 4, 1, 3)<<endl;
    */
    cout<<s.findKthNumber(3, 3, 5)<<endl;
    cout<<s.findKthNumber(2, 3, 6)<<endl;
    cout<<s.findKthNumber(45, 12, 471)<<endl;
    cout<<s.findKthNumber(42, 34, 401)<<endl;
    cout<<s.findKthNumber(11, 13, 57)<<endl;
    cout<<s.findKthNumber(12, 30, 101)<<endl;
}
