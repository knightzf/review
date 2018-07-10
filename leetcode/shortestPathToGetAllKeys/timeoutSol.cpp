#include "header.h"

class Solution {
private:
    int res;
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

        string finalKey;
        for(int i = 0; i < keyCnt; ++i)
            finalKey += 'a' + i;

        string key(keyCnt, ' ');
        res = INT_MAX;
        vector<vector<pair<string, int>>> visited(m, vector<pair<string, int>>(n, {"", INT_MAX}));
        dfs(grid, visited, m, n, startI, startJ, key, finalKey, 0);
        return res == INT_MAX ? -1 : res;
    }

    void dfs(vector<string>& grid, vector<vector<pair<string, int>>>& visited,
             int m, int n, int i, int j, string& key, string& finalKey, int steps)
    {
        //cout<<i<<" "<<j<<" "<<key<<" "<<steps<<" "<<visited[i][j].first<<" "<<visited[i][j].second<<endl;
        if(steps >= res || (visited[i][j].first == key && visited[i][j].second <= steps))
            return;
        //cout<<i<<" "<<j<<" "<<key<<" "<<steps<<endl;
        bool isKey = false;
        if(islower(grid[i][j]))
        {
            if(key[grid[i][j] - 'a'] == ' ')
            {
                isKey = true;
                key[grid[i][j] - 'a'] = grid[i][j];
                if(key == finalKey)
                {
                    res = min(res, steps);
                    key[grid[i][j] - 'a'] = ' ';
                    return;
                }
            }
        }

        auto temp = visited[i][j];
        visited[i][j] = {key, steps};

        static vector<int> offset{-1, 0, 1, 0, -1};
        for(int k = 0; k < 4; ++k)
        {
            int newI = i + offset[k];
            int newJ = j + offset[k + 1];
            if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && grid[newI][newJ] != '#')
            {
                if(!isupper(grid[newI][newJ]) || key[tolower(grid[newI][newJ]) - 'a'] != ' ')
                {
                    dfs(grid, visited, m, n, newI, newJ, key, finalKey, steps + 1);
                }
            }
        }

        if(isKey)
        {
            key[grid[i][j] - 'a'] = ' ';
        }

        visited[i][j] = temp;
    }
};

int main()
{
    Solution s;
    //vector<string> a{"@.a.#","###.#","b.A.B"};
    //vector<string> a{"@...a",".###A","b.BCc"};
    vector<string> a{"@abcdeABCDEFf"};
    cout<<s.shortestPathAllKeys(a)<<endl;
}
