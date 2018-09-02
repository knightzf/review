#include "header.h"

class Solution {
public:
    string orderlyQueue(string S, int K) {
        if(K > 1)
        {
            sort(S.begin(), S.end());
            return S;
        }
        char c = S[0];
        for(int i = 1; i < S.size(); ++i)
        {
            if(S[i] < c)
            {
                c = S[i];
            }
        }
        
        string res = S;
        for(int i = 0; i < S.size(); ++i)
        {
            if(S[i] == c)
            {
                string t = S.substr(i) + S.substr(0, i);
                if(t < res)
                    res = t;
            }
        }
        
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.orderlyQueue("xitavoyjqiupzadbdyymyvuteolyeerecnuptghlzsynozeuuvteryojyokpufanyrqqmtgxhyycltlnusyeyyqygwupcaagtkuq", 1)<<endl;
}
