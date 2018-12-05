#include "header.h"

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end());
        int time = -1;
        int hh = -1;
        int mm = -1;
        do {
            int hour = A[0] * 10 + A[1];
            int minute = A[2] * 10 + A[3];
            if(hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59)
            {
                int t = 60 * hour + minute;
                if(t > time)
                {
                    time = t;
                    hh = hour;
                    mm = minute;
                }
            }
        } while(std::next_permutation(A.begin(), A.end()));

        if(time != -1)
        {
            return to_string(hh / 10) + to_string(hh % 10) + ":" + 
                to_string(mm / 10) + to_string(mm % 10);
        }
        return "";
    }
};

int main()
{
    Solution s;
    vector<int> a{2, 0, 6, 6};
    cout<<s.largestTimeFromDigits(a)<<endl;
}
