class Solution {
    public:
        int integerBreak(int n) {
            if(n < 3)
            {
                return 1;
            }
            else if(n == 3)
            {
                return 2;
            }

            int res = n % 3;
            if(res == 0)
            {
                return pow(3, n/3);
            }
            else if(res == 1)
            {
                return pow(3, n/3 - 1) * 2 * 2;
            }
            else
            {
                return pow(3, n/3) * 2;
            }
        }
};
