#include "header.h"

class Solution {
public:    
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<vector<int>> v;
        map<vector<int>, int> m;
        int loopStart = N;

        for(int i = 0; i <= N; ++i)
        {
            std::cout<<i<<std::endl;
            /*for(int i : cells)
                cout<<i<<" ";
            cout<<endl;*/
            if(m.count(cells)) {
                loopStart = m[cells];
                break;
            }
            m.emplace(cells, i);
            v.emplace_back(cells);

            vector<int> t(8, 0);
            for(int j = 1; j < 7; ++j)
            {
                if(cells[j - 1] ^ cells[j + 1] == 0)
                {
                    t[j] = 1;
                }
            }

            cells = t;
        }

        if(loopStart == N) return v[N];
        //std::cout<<loopStart<<" "<<v.size()<<
        //" "<<loopStart + (N - loopStart) % (v.size() - loopStart)<<std::endl;
        return v[loopStart + (N - loopStart) % (v.size() - loopStart)];
    }
};

int main()
{
    Solution s;
    vector<int> a{1,0,0,1,0,0,1,0};
    const auto& r = s.prisonAfterNDays(a, 1000000000);
    //vector<int> a = {0,1,0,1,1,0,0,1};
    //const auto& r = s.prisonAfterNDays(a, 7);
    for(int i : r)
        cout<<i<<" ";
    cout<<endl;
}
