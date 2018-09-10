#include "header.h"

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int n = D.size();
        string num = to_string(N);
        int res = 0;
        for(int i = 1; i < num.size(); ++i)
        {
            res += pow(n, i);
        }

        impl(D, num, n, res);
        return res;
    }

    void impl(vector<string>& D, const string& num, int n, int& res)
    {
        if(num.empty()) {
            res += 1;
            return;
        }

        for(int i = 0; i < n; ++i)
        {
            if(D[i][0] < num[0])
            {
                res += pow(n, num.size() - 1);
            }
            else if(D[i][0] == num[0])
            {
                impl(D, num.substr(1), n, res);
            }
            else break;
        }
    }
};

int main()
{
    Solution s;
    //vector<string> a{"1", "3", "5", "7"};
    //cout<<s.atMostNGivenDigitSet(a, 100)<<endl;
    vector<string> a{"1", "4", "9"};
    cout<<s.atMostNGivenDigitSet(a, 4)<<endl;
}

