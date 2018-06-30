#include "header.h"

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        map<vector<int>, int> m;
        return dfs(boxes, m);
    }

    int dfs(vector<int>& boxes, map<vector<int>, int>& m)
    {
        if(m.count(boxes)) return m[boxes];

        int n = boxes.size();
        int res = 0;
        for(int i = 0; i < n;)
        {
            int j = i;
            while(j < boxes.size() && boxes[j] == boxes[i]) ++j;
            vector<int> newbox;
            newbox.insert(newbox.end(), boxes.begin(), boxes.begin() + i);
            newbox.insert(newbox.end(), boxes.begin() + j, boxes.end());
            res = max(res, (j - i) * (j - i) + dfs(newbox, m));
            i = j;
        }
        m[boxes] = res;
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{1,3,2,2,2,3,4,3,1};
    cout<<s.removeBoxes(a)<<endl;;
}
