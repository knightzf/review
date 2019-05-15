#include "header.h"

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int direction = 0, x = 0, y = 0;
        for(char c : instructions) {
            if(c == 'L') ++direction;
            else if(c == 'R') --direction;
            else {
                if(direction == 0) ++x;
                else if(direction == 1) --y;
                else if(direction == 2) --x;
                else ++y;
            }
            if(direction > 3) direction %= 4;
            else if(direction < 0) direction += 4;
        }
        return (x == 0 && y == 0) || direction != 0;
    }
};

int main()
{
    Solution s;
    //s.isRobotBounded("LLLRLLLRLLGLLGGRGLLLGGLRRRRRGLRLRLRLGGRGRGRLLLLLLGLLRLGLGLRLGGGRR");
    s.isRobotBounded("GGRGGRGGRGGR");
}
