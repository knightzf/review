#include "header.h"

class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> v{time[0] - '0', time[1] - '0', time[3] - '0', time[4] - '0'};
        sort(v.begin(), v.end());

        unordered_set<int> s(v.begin(), v.end());

        int minute = stoi(time.substr(3)); 
        for(int i = minute + 1; i < 60; ++i)
        {
            int a = i / 10;
            int b = i % 10;
            if(s.count(a) && s.count(b)) {
                time[3] = a + '0';
                time[4] = b + '0';
                return time;
            }
        }

        int hour = stoi(time.substr(0, 2)); 
        for(int i = hour + 1; i % 24 != hour; ++i)
        {
            int t = i % 24;
            int a = t / 10;
            int b = t % 10;
            if(s.count(a) && s.count(b)) {
                time[0] = a + '0';
                time[1] = b + '0';
                time[3] = v[0] + '0';
                time[4] = v[0] + '0';
                return time;
            }
        }

        return time;
    }
};

int main() {
    Solution s;
}
