#include "header.h"

struct Cell
{
    Cell(int value = 0) {
        isVal = true;
        val = value;
    }

    bool isVal;
    int val;

    vector<pair<int, int>> cells;

    int eval(vector<vector<Cell>>& grid)
    {
        if(isVal) return val;

        int res = 0;
        for(auto& c : cells)
            res += grid[c.first][c.second].eval(grid);
        return res;
    }

    void setVal(int value)
    {
        isVal = true;
        val = value;
        cells.clear();
    }

    void setFormula(vector<pair<int, int>>&& input)
    {
        isVal = false;
        val = 0;
        cells = input;
    }
};

class Excel {
private:
    vector<vector<Cell>> grid;

    void parse(vector<pair<int, int>>& v, const string& str)
    {
        auto f = [](const auto& str) {
            return make_pair(stoi(str.substr(1)), str[0] - 'A');
        };

        auto g = [&](const auto& str) {
            int idx = str.find(':');
            if(idx == -1)
            {
                v.emplace_back(f(str));
            }
            else
            {
                const auto& a = f(str.substr(0, idx));
                const auto& b = f(str.substr(idx + 1));
                for(int i = a.first; i <= b.first; ++i)
                {
                    for(int j = a.second; j <= b.second; ++j)
                    {
                        v.emplace_back(make_pair(i, j));
                    }
                }
            }
        };

        if(str.find(',') == -1)
        {
            g(str);
            return;
        }

        int startIdx = -1;
        for(int i = 0, n = str.size(); i < n; ++i)
        {
            if(str[i] == '"')
            {
                if(startIdx == -1)
                {
                    startIdx = i;
                }
                else
                {
                    const auto& s = str.substr(startIdx, i - startIdx - 1);
                    g(s);
                    startIdx = -1;
                }
            }
        }
    }

public:
    Excel(int H, char W) {
        grid = vector<vector<Cell>>(W - 'A' + 1, vector<Cell>(H));
    }

    void set(int r, char c, int v) {
        grid[r - 1][c - 'A'].setVal(v);
    }

    int get(int r, char c) {
        return grid[r - 1][c - 'A'].eval(grid);
    }

    int sum(int r, char c, vector<string> strs) {
        vector<pair<int, int>> v;
        for(const auto& s : strs)
        {
            parse(v, s);
        }

        grid[r - 1][c - 'A'].setFormula(move(v));
        return grid[r - 1][c - 'A'].eval(grid);
    }
};

int main() {
    //Solution s;

    Excel a(3, 'C');
    a.get(1, 'A');
    a.set(1, 'A', 1);
    a.get(1, 'A');
}
