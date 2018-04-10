My solution is straightfoward but need to handle quie a few different corner cases.

In the discussion there's a greate solution.\
https://leetcode.com/problems/decode-ways-ii/discuss/105274/Python-Straightforward-with-Explanation

The idea is to keep track of 3 numbers:
* e0 = current number of ways we could decode, ending on any number;
* e1 = current number of ways we could decode, ending on an open 1;
* e2 = current number of ways we could decode, ending on an open 2;

(Here, an ¡°open 1¡± means a 1 that may later be used as the first digit of a 2 digit number, \
because it has not been used in a previous 2 digit number.)

```C++
class Solution {
public:
    int numDecodings(string s) {
        long e0 = 1, e1 = 0, e2 = 0, f0, f1, f2;
        for ( char c : s ) {
            if ( '*' == c ) {
                f0 = 9 * e0 + 9 * e1 + 6 * e2;
                f1 = f2 = e0;
            } else {
                f0 = int(c > '0') * e0 + e1 + int(c < '7') * e2;
                f1 = '1' == c ? e0 : 0;
                f2 = '2' == c ? e0 : 0;
            }
            e0 = f0 % 1000000007;
            e1 = f1;
            e2 = f2;
        }
        return int(e0);
    }
};
```
