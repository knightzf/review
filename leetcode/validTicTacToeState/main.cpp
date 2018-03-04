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
    bool validTicTacToe(vector<string>& board) {
        int n = 3;
        int xCount = 0;
        int oCount = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == 'X')
                {
                    ++xCount;
                }
                else if(board[i][j] == 'O')
                {
                    ++oCount;
                }
            }
        }

        if(xCount == oCount || xCount == oCount + 1)
        {
            int goodCount = 0;
            for(int i = 0; i < 3; ++i)
            {
                if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
                {
                    ++goodCount;
                    if( (board[i][0] == 'X' && xCount != oCount + 1) ||
                        (board[i][0] == 'O' && xCount != oCount)) return false;
                }
                if(goodCount > 1) return false;

                if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
                {
                    if( (board[0][i] == 'X' && xCount != oCount + 1) ||
                        (board[0][i] == 'O' && xCount != oCount)) return false;
                    ++goodCount;
                }
                if(goodCount > 1) return false;
            }

            if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[2][2] == board[1][1])
            {
                if( (board[1][1] == 'X' && xCount != oCount + 1) ||
                    (board[1][1] == 'O' && xCount != oCount)) return false;
                ++goodCount;
            }
            if(goodCount > 1) return false;

            if(board[0][2] != ' ' && board[1][1] == board[0][2] && board[1][1] == board[2][0])
            {
                if( (board[1][1] == 'X' && xCount != oCount + 1) ||
                    (board[1][1] == 'O' && xCount != oCount)) return false;
                ++goodCount;
            }
            if(goodCount > 1) return false;
        }
        else
        {
            return false;
        }

        return true;
    }
};



int main() {
    Solution s;
    vector<string> a{"XXX", "XOO", "OO "};
    std::cout<<s.validTicTacToe(a)<<std::endl;
}
