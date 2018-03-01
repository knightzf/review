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

class TicTacToe {
private:
    vector<vector<int>> board;
    int n;
public:
    /** Initialize your data structure here. */
    TicTacToe(int k) {
        board = vector<vector<int>>(k, vector<int>(k, 0));
        n = k;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
        int left = col - 1;
        int right = col + 1;
        bool win = true;
        while(left >= 0 || right <= n - 1)
        {
            if(left >= 0)
                if(board[row][left--] != player) {win = false; break;}
            if(right <= n - 1)
                if(board[row][right++] != player) {win = false; break;}
        }
        if(win) return player;

        int up = row - 1;
        int down = row + 1;
        win = true;
        while(up >= 0 || down <= n - 1)
        {
            if(up >= 0)
                if(board[up--][col] != player) {win = false; break;}
            if(down <= n - 1)
                if(board[down++][col] != player) {win = false; break;}
        }
        if(win) return player;


        if(row == col)
        {
            int left = row - 1;
            int right = row + 1;
            win = true;
            while(left >= 0 || right <= n - 1)
            {
                if(left >= 0)
                {
                    if(board[left][left] != player) {win = false; break;}
                    --left;
                }
                if(right <= n - 1)
                {
                    if(board[right][right] != player) {win = false; break;}
                    ++right;
                }
            }
            if(win) return player;
        }

        if(row + col == n - 1)
        {
            std::pair<int, int> left{row - 1, col + 1};
            std::pair<int, int> right{row + 1, col - 1};
            win = true;
            while(left.first >= 0 || right.second >= 0)
            {
                if(left.first >= 0)
                {
                    if(board[left.first][left.second] != player) {win = false; break;}
                    --left.first; ++left.second;

                }
                if(right.second >= 0)
                {
                    if(board[right.first][right.second] != player) {win = false; break;}
                    ++right.first; --right.second;
                }
            }
            if(win) return player;
        }

        return 0;
    }
};


int main() {
    //Solution s;
    TicTacToe t(3);
    t.move(0, 0, 1);
    t.move(0, 2, 2);
    t.move(2, 2, 1);
    t.move(1, 1, 2);
    t.move(2, 0, 1);
    std::cout<<"here"<<std::endl;
    std::cout<<t.move(1, 0, 2)<<std::endl;
    std::cout<<t.move(2, 1, 1)<<std::endl;
}
