#include "header.h"

class Solution {
public:
    struct Square
    {
        int x;
        int y;
        int val;
    };

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int goal = n * n;
        vector<vector<int>> visited(n, vector<int>(n, INT_MAX));
        Square p{0, 0, 1};
        deque<Square> q;
        q.push_back(p);
        visited[n - 1][0] = 0;
        int qsize = q.size();
        int steps = 1;
        while(!q.empty())
        {
            for(int i = 0; i < qsize; ++i)
            {
                const auto& t = q.front();
                for(int j = 1; j < 7; ++j)
                {
                    int val = t.val + j;
                    if(val == goal) return steps;
                    if(val > goal) break;
                    int x = n - 1 - (val - 1) / n;
                    int y = (val % n) == 0 ? n - 1 : ((val % n) - 1);
                    if((x % 2) != ((n - 1) % 2)) y = n - 1 - y;
                    if(steps > visited[x][y]) continue;  
                    visited[x][y] = steps;                  
                    if(board[x][y] != -1)
                    {
                        val = board[x][y];
                        if(val == goal) return steps;
                        x = n - 1 - (val - 1) / n;
                        y = (val % n) == 0 ? n - 1 : ((val % n) - 1);
                        if((x % 2) != ((n - 1) % 2)) y = n - 1 - y;
                        if(steps >= visited[x][y]) continue;
                        //visited[x][y] = steps;
                    }
                    cout<<val<<" "<<x<<" "<<y<<endl;
                    q.push_back(Square{x, y, val});
                }
                q.pop_front();
            }

            qsize = q.size();
            ++steps;
        }

        return -1;
    }
};

int main()
{
    /*int val = 12;
    int n = 6;
    int x = (val - 1) / n;
    int y = (val % n) == 0 ? n - 1 : ((val % n) - 1);
    if((x % 2) != 0) y = n - 1 - y;
    cout<<x<<" "<<y<<endl;*/
    Solution s;
    //vector<vector<int>> a{{-1,7,-1},{-1,6,9},{-1,-1,2}};
    //vector<vector<int>> a{{1,1,-1},{1,1,1},{-1,1,1}};
    //vector<vector<int>> a{{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    //vector<vector<int>> a{{-1,-1,-1,-1,48,5,-1},{12,29,13,9,-1,2,32},{-1,-1,21,7,-1,12,49},{42,37,21,40,-1,22,12},{42,-1,2,-1,-1,-1,6},{39,-1,35,-1,-1,39,-1},{-1,36,-1,-1,-1,-1,5}};
    vector<vector<int>> a{{-1,-1,-1,46,47,-1,-1,-1},{51,-1,-1,63,-1,31,21,-1},{-1,-1,26,-1,-1,38,-1,-1},{-1,-1,11,-1,14,23,56,57},{11,-1,-1,-1,49,36,-1,48},{-1,-1,-1,33,56,-1,57,21},{-1,-1,-1,-1,-1,-1,2,-1},{-1,-1,-1,8,3,-1,6,56}};
    cout<<s.snakesAndLadders(a)<<endl;
}
