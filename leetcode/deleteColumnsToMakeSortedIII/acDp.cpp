#include "header.h"

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size(), m = A[0].size();
        int res = m - 1;

        vector<int> dp(m, 1); //dp[i] -> longest ordered substring ends at index i
        dp[0] = 1;
        for(int j = 1; j < m; ++j)
        {            
            for(int k = 0; k < j; ++k)
            {
                bool candidate = true;
                for(int i = 0; i < n; ++i)
                {
                    if(A[i][k] > A[i][j]) {
                        candidate = false;
                        break;
                    }
                }

                if(candidate)
                {
                    dp[j] = max(dp[j], dp[k] + 1);
                }
            }
            
            res = min(res, j + 1 - dp[j] + m - j - 1);
        }
        /*for(int i : dp)
            cout<<i<<" ";
        cout<<endl;*/
        return res; 
    }
};

int main()
{
    Solution s;
    //vector<string> a{"babca","bbazb"};
    //vector<string> a{"edcba"};
    //vector<string> a{"ghi","def","abc"};
    vector<string> a{"deehdecfcgegffegghfhfaagcaaffbfahcfaghgdfggbbddbff","dchhgcbahdbdgbbaafhbgfggcbebfacdebhfgcfaafcgbgbggg","hehdggagfabdfbhegebhaaddcaghhegeegdgegagehhdhheecd","fhbbagbdffedafacbeahddbgagggdafceeabaffhhhhcedcfbh","caaefgdgefeahcgfgccaacdfabdgdbdhdbhbhfadbeaegbbdce","habgbahaeebeacccbdhfhddegfebheeffdbcbgfahhgbhcheeb","gfaaedgcachcehgdghebbhegbfagdgcdcgebddbdccbedbbhcd","badaebdbdgeadbfgchaegaddgdhdgaeaaedagacgbdecfdghca","eefcceffcggeefbecaceadbdcfccgbfgffgahfgeebafdcfhhb","aeebdahabfecbafgbcchbhdeecaadaccbahghcbdcfaeagehha"};
    cout<<s.minDeletionSize(a)<<endl;
}
