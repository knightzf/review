class Solution {
    public:
        bool isPowerOfTwo(int n)
        {
            if((n & (n - 1)) == 0)
            {
                return true;
            }

            return false;
        }

        vector<int> countBits(int num) {
            vector<int> result;
            int lastTwoPow = 0;
            for(int i = 0; i <= num; ++i)
            {
                if(i == 0)
                {
                    result.push_back(0);
                }
                else
                {
                    if(isPowerOfTwo(i))
                    {
                        lastTwoPow = i;
                        result.push_back(1);
                    }
                    else
                    {
                        result.push_back(1 + result[i - lastTwoPow]);
                    }
                }
            }

            return result;
        }
};
