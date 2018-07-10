#include "header.h"

struct State
{
    int x;
    int y;
    int key;

    bool operator<(const State& rhs) const
    {
        return make_tuple(x, y, key) < make_tuple(rhs.x, rhs.y, rhs.key);
    }
};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int startI = 0, startJ = 0;
        int keyCnt = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '@')
                {
                    startI = i;
                    startJ = j;
                }
                else if(islower(grid[i][j]))
                {
                    ++keyCnt;
                }
            }
        }

        int finalKey = 0;
        for(int i = 0; i < keyCnt; ++i)
            finalKey += 1 << i;

        set<State> states;

        deque<State> q;
        q.push_back(State{startI, startJ, 0});
        int qsize = q.size();
        int steps = 0;
        while(qsize)
        {
            for(int i = 0; i < qsize; ++i)
            {
                const auto& s = q.front();
                //cout<<s.x<<" "<<s.y<<" "<<s.key<<endl;
                if(s.key == finalKey) return steps;

                if(states.count(s) == 0)
                {
                    states.insert(s);

                    static vector<int> shift{-1, 0, 1, 0, -1};
                    for(int k = 0; k < 4; ++k)
                    {
                        int x = s.x + shift[k];
                        int y = s.y + shift[k + 1];
                        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '#')
                        {
                            if(islower(grid[x][y]))
                            {
                                State t{x, y, s.key | (1 << grid[x][y] - 'a')};
                                if(states.count(t) == 0)
                                {
                                    q.push_back(t);
                                }
                            }
                            else if(isupper(grid[x][y]))
                            {
                                if(s.key & (1 << grid[x][y] - 'A'))
                                {
                                    State t{x, y, s.key};
                                    if(states.count(t) == 0)
                                    {
                                        q.push_back(t);
                                    }
                                }
                            }
                            else
                            {
                                State t{x, y, s.key};
                                if(states.count(t) == 0)
                                {
                                    q.push_back(t);
                                }
                            }
                        }
                    }
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
    Solution s;
    //vector<string> a{"@.a.#","###.#","b.A.B"};
    vector<string> a{"@...a",".###A","b.BCc"};
    //vector<string> a{"@abcdeABCDEFf"};
    cout<<s.shortestPathAllKeys(a)<<endl;
}
