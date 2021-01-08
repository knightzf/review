class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.empty() || k == num.size()) return "0";
        int n = num.size();
        for(int i = 0; i <= k; ++i) {
            if(num[i] == '0') {
                int j = i;
                while(j < n && num[j] == '0') ++j;
                return removeKdigits(num.substr(j), k - i);
            }
        }
        string res;
        int startIdx = 0, minIdx = 0;
        while(k > 0 && startIdx < n) {
            if(k == n - startIdx) {
                startIdx = n;
                break;
            }
            for(int i = startIdx; i <= startIdx + k; ++i) {
                if(num[i] < num[minIdx]) minIdx = i;
            }
            res += num[minIdx];
            k -= minIdx - startIdx;
            startIdx = minIdx + 1;
            minIdx = startIdx;
        }
        res += num.substr(startIdx);
        return res.substr(0, n - k);
    }
};
