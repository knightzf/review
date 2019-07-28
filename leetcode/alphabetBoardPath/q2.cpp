#include "header.h"

class Solution {
public:
    string alphabetBoardPath(string target) {
        int x = 0, y = 0;
        string res;
        for(char c : target) {
            if('a' + x * 5 + y != c) {
                int i = (c - 'a') / 5, j = (c - 'a') % 5;
                res += addPath(x, y, i, j);
                x = i, y = j;
            }
            res += '!';
        }
        return res;
    }

    string addPath(int x, int y, int i, int j) {
        string res;
        if(x == 5 && y == 0) {
            res += 'U';
            --x;
        }
        bool isz = i == 5 && j == 0;
        if(isz) --i;

        if(x > i) res += string(x - i, 'U');
        else if(x < i) res += string(i - x, 'D');
        if(y > j) res += string(y - j, 'L');
        else if(y < j) res += string(j - y, 'R');

        if(isz) res += 'D';
        return res;
    }
};

int main()
{
}
