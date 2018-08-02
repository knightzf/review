#include "header.h"

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.empty()) return 0;

        int n = courses.size();
        for(int i = 0; i < n; ++i)
        {
            courses[i][1] = courses[i][1] - courses[i][0] + 1;
        }

        /*sort(courses.begin(), courses.end(), [](const auto& a, const auto& b){
                if(a[0] < b[0]) return true;
                if(a[0] == b[0]) return a[1] < b[1];
                return false;
             });*/
        sort(courses.begin(), courses.end(), [](const auto& a, const auto& b){
                if(a[1] < b[1]) return true;
                if(a[1] == b[1]) return a[0] < b[0];
                return false;
             });

        for(int i = 0; i < n; ++i)
            cout<<courses[i][0]<<" "<<courses[i][1]<<endl;
        int t = 1;
        int res = 0;
        int i = 1;
        set<int> s{courses[0][0]};
        while(i < n)
        {
            if(!s.empty() && courses[i][1] - t >= *s.begin())
            {
                ++res;
                t += *s.begin();
                cout<<"add "<<*s.begin()<<endl;
                s.clear();
                s.insert(courses[i][0]);
            }
            else
            {
                s.insert(courses[i][0]);
            }
            ++i;
        }
        ++res;

        return res;
    }
};

int main() {
    Solution s;
    //vector<vector<int>> a{{5,15},{3,19},{6,7},{2,10},{5,16},{8,14},{10,11},{2,19}};
    //vector<vector<int>> a{{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    vector<vector<int>> a{{7,17},{3,12},{10,20},{9,10},{5,20},{10,19},{4,18}};
    cout<<s.scheduleCourse(a)<<endl;
}
