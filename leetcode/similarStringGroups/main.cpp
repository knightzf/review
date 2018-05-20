#include "header.h"

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        vector<int> parent(n, - 1);
        for(int i = 0; i < n; ++i) parent[i] = i;
        for(int i = 0; i < n; ++i)
        {
            //if(parent[i] == -1) parent[i] = i;
            for(int j = i + 1; j < n; ++j)
            {
                if(similar(A[i], A[j]))
                {
                    //std::cout<<i<<" "<<j<<endl;
                    int parentI = getParent(parent, i);
                    int parentJ = getParent(parent, j);
                    if(parentI != parentJ)
                    {
                        parent[parentJ] = parentI;
                    }
                }
            }
        }

        /*for(int i = 0; i < n; ++i)
        {
            cout<<A[i]<<" "<<getParent(parent, i)<<endl;
        }*/

        unordered_set<int> s;
        for(int i = 0; i < n; ++i)
        {
            s.insert(getParent(parent, i));
        }
        return s.size();
    }

    int getParent(vector<int>& parent, int idx)
    {
        while(parent[idx] != idx)
        {
            idx = parent[idx];
        }

        return idx;
    }

    bool similar(const string& a, const string& b)
    {
        vector<int> diffIdx;
        for(int i = 0; i < a.size(); ++i)
        {
            if(a[i] != b[i])
            {
                diffIdx.push_back(i);
            }
            if(diffIdx.size() > 2) return false;
        }

        if(diffIdx.size() != 2) return false;
        return a[diffIdx[0]] == b[diffIdx[1]] && a[diffIdx[1]] == b[diffIdx[0]];
    }
};

int main()
{
    Solution s;
    //vector<string> a{"kccomwcgcs","socgcmcwkc","sgckwcmcoc","coswcmcgkc","cowkccmsgc","cosgmccwkc","sgmkwcccoc","coswmccgkc","kowcccmsgc","kgcomwcccs"};
    vector<string> a{"ajdidocuyh","djdyaohuic","ddjyhuicoa","djdhaoyuic","ddjoiuycha","ddhoiuycja","ajdydocuih","ddjiouycha","ajdydohuic","ddjyouicha"};
    s.numSimilarGroups(a);
}
