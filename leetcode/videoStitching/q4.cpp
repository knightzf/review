#include "header.h"

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(), [](const auto& a, const auto& b) {
            if(a[0] < b[0]) return true;
            if(a[0] == b[0]) return a[1] < b[1];
            return false;
        });
        if(clips[0][0] != 0) return -1;
        stack<vector<int>> s;
        for(const auto& v : clips)
        {
            cout<<v[0]<<" "<<v[1]<<endl;
            if(s.empty()) s.push(v);
            else
            {
                if(v[1] > s.top()[1])
                {
                    auto t = s.top();
                    s.pop();
                    if(s.empty()) {
                        if(v[0] == 0) s.push(v);
                        else {
                            s.push(t);
                            s.push(v);
                        }
                    }
                    else if(v[0] <= s.top()[1])
                    {
                        s.push(v);
                    }
                    else
                    {
                        s.push(t);
                        s.push(v);
                    }                    
                }
            }
            cout<<s.top()[1]<<endl;
            if(s.top()[1] >= T) return s.size();
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
    cout<<s.videoStitching(a, 10)<<endl;
}
