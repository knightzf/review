#include "header.h"

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        vector<pair<int, int>> island;
        int m = A.size(), n = A[0].size();
        static vector<int> shift{-1, 0, 1, 0, -1};
        bool found = false;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(A[i][j] == 1)
                {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    int qsize = q.size();
                    while(!q.empty())
                    {
                        for(int k = 0; k < qsize; ++k)
                        {
                            pair<int, int> p = q.front();                            
                            q.pop();
                            visited[p.first][p.second] = true;
                            island.emplace_back(p);
                            for(int l = 0; l < 4; ++l)
                            {
                                if(p.first + shift[l] >= 0 && p.first + shift[l] < m && 
                                   p.second + shift[l + 1] >= 0 && p.second + shift[l + 1] < n &&
                                   A[p.first + shift[l]][p.second + shift[l + 1]] == 1 &&
                                   visited[p.first + shift[l]][p.second + shift[l + 1]] == false)
                                {
                                    visited[p.first + shift[l]][p.second + shift[l + 1]] = true;
                                    q.push(make_pair(p.first + shift[l], p.second + shift[l + 1]));
                                }
                            }
                        }

                        qsize = q.size();
                    }
                    found = true;              
                    break;
                }
            }
            if(found) break;
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        queue<pair<int, int>> q;
        for(auto& p : island) 
        {
            visited[p.first][p.second] = true;
            q.push(p);
        }
        int qsize = q.size();
        while(!q.empty())
        {
            for(int k = 0; k < qsize; ++k)
            {
                pair<int, int> p = q.front();                            
                q.pop();
                for(int l = 0; l < 4; ++l)
                {
                    if(p.first + shift[l] >= 0 && p.first + shift[l] < m && 
                       p.second + shift[l + 1] >= 0 && p.second + shift[l + 1] < n &&
                       visited[p.first + shift[l]][p.second + shift[l + 1]] == false)
                    {
                        //cout<<p.first + shift[l]<<" "<<p.second + shift[l + 1]<<" "<<
                        //A[p.first + shift[l]][p.second + shift[l + 1]]<<endl;
                        if(A[p.first + shift[l]][p.second + shift[l + 1]] == 0)
                        {
                            visited[p.first + shift[l]][p.second + shift[l + 1]] = true;
                            q.push(make_pair(p.first + shift[l], p.second + shift[l + 1]));
                        }
                        else return res;
                    }
                }
            }            
            ++res;
            qsize = q.size();
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{0, 1}, {1, 0}};
    cout<<s.shortestBridge(a)<<endl;;
}

