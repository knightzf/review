#include "header.h"

class TicTacToe {
private:
    int m_n;
    vector<vector<int>> m_state;
public:
    TicTacToe(int n) : m_n(n) {
        m_state = vector<vector<int>>(n, vector<int>(n, 0));
    }

    int move(int row, int col, int player) {
        m_state[row][col] = player;
        int rowCnt = 0, colCnt = 0, leftDiag = 0, rightDiag = 0;
        for(int i = 0; i < m_n; ++i) {
            if(m_state[i][col] == player) ++rowCnt;
            if(m_state[row][i] == player) ++colCnt;
            if(m_state[i][i] == player) ++leftDiag;
            if(m_state[i][m_n - 1 - i] == player) ++rightDiag;
        }
        if(rowCnt == m_n || colCnt == m_n || leftDiag == m_n || rightDiag == m_n) return player;
        return 0;
    }
};

int main()
{
    //Solution s;
}