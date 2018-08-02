#include "header.h"

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), [](const auto& a, const auto& b){
                return a[1] < b[1];
             });


        priority_queue<int> q;
        int res = 0;
        int t = 0;
        for(int i = 0; i < n; ++i)
        {
            if(t + courses[i][0] <= courses[i][1])
            {
                q.push(courses[i][0]);
                t += courses[i][0];
            }
            else if(!q.empty() && q.top() > courses[i][0])
            {
                t = t - q.top() + courses[i][0];
                q.pop();
                q.push(courses[i][0]);
            }
        }
        return q.size();
    }
};

int main() {
    Solution s;
    vector<vector<int>> a{{5,15},{3,19},{6,7},{2,10},{5,16},{8,14},{10,11},{2,19}};
    //vector<vector<int>> a{{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    //vector<vector<int>> a{{7,17},{3,12},{10,20},{9,10},{5,20},{10,19},{4,18}};
    cout<<s.scheduleCourse(a)<<endl;
}
