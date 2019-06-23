#include "header.h"

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double sum = 0;
        int cnt = 0, mi = 256, mx = 0, mode = 0, modecnt = 0;
        for(int i = 0; i < 256; ++i) {
            sum += i * count[i];
            cnt += count[i];
            if(count[i]) {
                mi = min(mi, i);
                mx = max(mx, i);
                if(count[i] > modecnt) {
                    modecnt = count[i];
                    mode = i;
                }
            }
        }
        vector<double> res{mi, mx, sum / cnt, 0, mode};
        int left = 0, right = 0, leftidx = cnt / 2, rightidx = cnt / 2 + 1;
        bool hasleft = false, hasright = false;
        cnt = 0;
        for(int i = 0; i < 256; ++i) {
            if(count[i]) {
                cnt += count[i];
                if(!hasleft && cnt >= leftidx) {
                    left = i;
                    hasleft = true;
                }
                if(!hasright && cnt >= rightidx) {
                    right = i;
                    break;
                }
            }
        }
        if(cnt & 1) res[3] = left;
        else res[3] = (left + right) / 2.0;
        return res;
    }
};

int main()
{
    Solution s;
}
