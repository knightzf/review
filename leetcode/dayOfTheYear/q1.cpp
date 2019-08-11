#include "header.h"

class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        bool isleap = checkleap(year);
        vector<int> monthdays{0, 31, 28 + (isleap ? 1 : 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int res = 0;
        for(int i = 1; i < month; ++i) res += monthdays[i];
        return res + day;
    }

    bool checkleap(int year) {
        if(year % 4) return false;
        if(year % 100) return true;
        if(year % 400 == 0) return true;
        return false;
    }
};

int main()
{
    Solution s;
}
