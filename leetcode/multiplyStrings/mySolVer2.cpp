#include "header.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() > num2.size())
            std::swap(num1, num2);

        string res;
        for(int i = 0; i < num1.size(); ++i)
        {
            if(num1[i] != '0')
            {
                int n = num1[i] - '0';
                string t(num1.size() - i - 1, '0');
                int carry = 0;
                for(int j = num2.size() - 1; j >= 0; --j)
                {
                    int k = (num2[j] - '0') *  n + carry;
                    carry = k / 10;
                    t += (k % 10) + '0';
                }
                if(carry)
                    t += carry + '0';

                add(res, t);
                //std::cout<<n<<" "<<num2<<" "<<t<<" "<<res<<std::endl;
            }
            else
                add(res, "0");
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
private:
    void add(string& res, const string& t)
    {
        if(res.empty())
            res = t;
        else
        {
            int i = 0, j = 0;
            int m = res.size(), n = t.size();
            int carry = 0;
            while(i < m)
            {
                int temp = 0;
                if(j < n)
                    temp = res[i] - '0' + t[j] - '0' + carry;
                else
                    temp = res[i] - '0' + carry;

                carry = temp > 9 ? 1 : 0;
                res[i] = temp % 10 + '0';
                ++i;
                ++j;
            }
            if(carry)
                res += carry + '0';
        }
    }
};

int main()
{
    Solution s;
    std::cout<<s.multiply("123", "4567")<<std::endl;
}
