#include "header.h"

class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        int i = 0, j = 0;
        vector<Interval> res;
        while(i < A.size() && j < B.size())
        {
            if(A[i].start > B[j].start)
            {
                swap(A, B);
                swap(i, j);
            }
            
            if(A[i].end >= B[j].start)
            {
                if(A[i].end >= B[j].end)
                {
                    res.push_back(B[j]);
                    ++j;
                }
                else
                {
                    res.emplace_back(Interval(B[j].start, A[i].end));
                    ++i;
                }      
            }
            else
            {
                ++i;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}

