#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();

        vector<int> firstRow = board[0];
        vector<int> firstCol;
        for(int i = 0; i < n; ++i)
        {
            firstCol.push_back(board[i][0]);
        }

        int t = 0;
        for(int i = 0; i < n; ++i)
        {
            t += firstRow[i];
        }
        if(n % 2 == 0)
        {
            if(t != n / 2) return -1;
        }
        else
        {
            if(t != n / 2 && t != n / 2 + 1) return -1;
        }

        t = 0;
        for(int i = 0; i < n; ++i)
        {
            t += firstCol[i];
        }

        if(n % 2 == 0)
        {
            if(t != n / 2) return -1;
        }
        else
        {
            if(t != n / 2 && t != n / 2 + 1) return -1;
        }

        vector<int> oppRow = firstRow;
        for_each(oppRow.begin(), oppRow.end(), [](int& c){c = c == 0 ? 1 : 0;});
        vector<int> oppCol = firstCol;
        for_each(oppCol.begin(), oppCol.end(), [](int& c){c = c == 0 ? 1 : 0;});

        int sameRowCnt = 1;
        int misplacedRowCnt = 0;
        int sameColCnt = 1;
        int misplacedColCnt = 0;
        for(int i = 1; i < n; ++i)
        {
            if(board[i] == firstRow)
            {
                misplacedRowCnt += (i % 2 == 1);
                ++sameRowCnt;
            }
            else if(board[i] == oppRow) misplacedRowCnt += (i % 2 == 0);
            else if(board[i] != oppRow) return -1;

            if(sameCol(board, firstCol, i))
            {
                misplacedColCnt += (i % 2 == 1);
                ++sameColCnt;
            }
            else if(sameCol(board, oppCol, i)) misplacedColCnt += (i % 2 == 0);
            else if(!sameCol(board, oppCol, i)) return -1;
        }

        if(n % 2 == 0)
        {
            if(sameRowCnt != n / 2 || sameColCnt != n /2) return -1;
        }
        else
        {
            if((sameRowCnt != n / 2 && sameRowCnt != n / 2 + 1)
               || (sameColCnt != n /2 && sameColCnt != n /2 + 1)) return -1;
        }

        std::cout<<misplacedRowCnt<<" "<<misplacedColCnt<<std::endl;

        int res = 0;
        if(n % 2 == 0)
        {
            res += min(misplacedRowCnt, n - misplacedRowCnt) / 2 + min(misplacedColCnt, n - misplacedColCnt) / 2;
        }
        else
        {
            if(sameRowCnt == n / 2)
            {
                res += (n - misplacedRowCnt)/2;
            }
            else
            {
                res +=  misplacedRowCnt/2;
            }

            if(sameColCnt == n / 2)
            {
                res += (n - misplacedColCnt)/2;
            }
            else
            {
                res +=  misplacedColCnt/2;
            }
        }

        return res;
    }

private:
    bool sameCol(const vector<vector<int>>& board, const vector<int>& col, int i)
    {
        for(int j = 0; j < board.size(); ++j)
        {
            if(board[j][i] != col[j]) return false;
        }

        return true;
    }
};

int main() {
    Solution s;
    //std::vector<std::vector<int>> a{{0,1,1,0},{0,1,1,0},{1,0,0,1},{1,0,0,1}};
    std::vector<std::vector<int>> a{{1,1,0},{0,0,1},{0,0,1}};
    //std::vector<std::vector<int>> a{{0,0,1,1,1,1,0},{0,0,1,1,1,1,0},{0,0,1,1,1,1,0},{0,1,0,0,1,1,1},{0,1,0,0,1,1,1},{0,1,0,0,1,1,1},{0,0,1,1,1,1,0}};
    //std::vector<std::vector<int>> a{{0,1,1,0},{1,1,0,0},{0,0,1,1},{1,0,0,1}};
    std::cout<<s.movesToChessboard(a)<<std::endl;
}
