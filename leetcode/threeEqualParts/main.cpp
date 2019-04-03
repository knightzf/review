#include "header.h"

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        size_t n = A.size();
        set<size_t> s;
        for(size_t i = 0; i < n; ++i)
        {
            if(A[i] == 1) s.insert(i);
        }

        if(s.empty()) return {0, 2};
        if(s.size() % 3 != 0) return {-1, -1};

        size_t startIdx = 0, endIdx = n - 2;
        while(startIdx < endIdx)
        {
            int mid = (startIdx + endIdx) / 2;
            
            cout<<startIdx<<" "<<endIdx<<" "<<mid<<endl;

            int i = *s.lower_bound(0);

            auto iter = s.upper_bound(mid);
            if(iter == s.end())
            {
                endIdx = mid;
                continue;
            }
            else
            {
                int j = *iter;
                int distance = mid - i;
                int endJ = j + mid - i;
                iter = s.upper_bound(endJ);
                if(iter == s.end() || (*iter + distance >= n))
                {
                    endIdx = mid;
                    continue;
                }
                else if(*iter + distance < n - 1)
                {
                    startIdx = mid + 1;
                    continue;
                }
                else
                {
                    int k = *iter;
                    while(i <= mid)
                    {
                        if(!(A[i] == A[j] && A[j] == A[k]))
                        {
                            return {-1, -1};
                        }
                        ++i; ++j; ++k;
                    }
                    return {mid, j};
                }
            }            
        }
        return {-1, -1};
    }
};

int main()
{
    Solution s;
    //vector<int> a{1, 0, 1, 0, 1};
    vector<int> a{0, 1, 0, 1, 1};
    const auto& r = s.threeEqualParts(a);
    cout<<r[0]<<" "<<r[1]<<endl;
}