class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0;
        for(int numChars = 1; numChars <= 26; ++numChars) {
            int i = 0, j = 0, n = s.size();
            int uniqueCount = 0, atLeastKCount = 0;
            vector<int> count(26, 0);
            while(j < n) {
                if(uniqueCount <= numChars) {
                    int idx = s[j++] - 'a';
                    if(++count[idx] == 1) {
                        ++uniqueCount;
                    }
                    if(count[idx] == k) {
                        ++atLeastKCount;
                    }
                } else {
                    int idx = s[i++] - 'a';
                    if(--count[idx] == 0) {
                        --uniqueCount;
                    }
                    if(count[idx] == k - 1) {
                        --atLeastKCount;
                    }
                }
                
                if(uniqueCount == numChars && atLeastKCount == numChars) {
                    res = max(res, j - i);
                }
            }
        }
        return res;
    }
};
