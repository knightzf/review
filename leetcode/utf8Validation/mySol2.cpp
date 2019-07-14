#include "header.h"

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int one = 0, two = 6, three = 14, four = 30;
        int sub = 2;
        for(int i = 0, n = data.size(), cnt = 0; i < n; ++i) {
            if((data[i] >> 7) == 0) {
                continue;
            }
            else if((data[i] >> 3) == four) cnt = 3;
            else if((data[i] >> 4) == three) cnt = 2;
            else if((data[i] >> 5) == two) cnt = 1;
            else return false;
            int j = i;
            while(cnt--) {
                ++j;
                if(j == n || (data[j] >> 6) != sub) return false;
            }
            i = j;
        }
        return true;
    }
};


int main()
{
    Solution s;
    vector<int> a{248,130,130,130};
    cout<<s.validUtf8(a)<<endl;
}