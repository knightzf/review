#include "header.h"

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j) {
                if(board[i][j] == 'X') ++cnt1;
                else if(board[i][j] == 'O') ++cnt2;
            }
        if(cnt2 > cnt1 || cnt1 > cnt2 + 1) return false;
        int win1 = 0, win2 = 0;
        for(int i = 0; i < 3; ++i) {
            if(board[i] == "XXX") ++win1;
            else if(board[i] == "OOO") ++win2;
            string t{board[0][i], board[1][i], board[2][i]};
            if(t == "XXX") ++win1;
            else if(t == "OOO") ++win2;
        }
        string t{board[0][0], board[1][1], board[2][2]};
        if(t == "XXX") ++win1;
        else if(t == "OOO") ++win2;
        string t1{board[0][2], board[1][1], board[2][0]};
        if(t1 == "XXX") ++win1;
        else if(t1 == "OOO") ++win2;
        if(win1 && win2 || (win1 && cnt2 == cnt1) || (win2 && cnt1 > cnt2)) return false;
        return true;
    }
};


int main()
{
    Solution s;
}