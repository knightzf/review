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

class SnakeGame {
private:
    int m;
    int n;
    vector<pair<int, int>> foods;
    int foodIdx = 0;
    std::list<pair<int, int>> snake;
    std::set<pair<int, int>> points;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) : n(width), m(height), foods(food){
        const auto& p = std::make_pair(0, 0);
        snake.push_back(p);
        points.insert(p);
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto next = snake.front();
        if(direction == "U")
            --next.first;
        else if(direction == "L")
            --next.second;
        else if(direction == "R")
            ++next.second;
        else if(direction == "D")
            ++next.first;

        if(next.first < 0 || next.first >= m || next.second < 0 || next.second >= n) return -1;

        if(foodIdx < foods.size() && next == foods[foodIdx])
        {
            if(points.find(next) != points.end()) return -1;

            snake.push_front(next);
            points.insert(next);
            ++foodIdx;
        }
        else
        {
            points.erase(snake.back());
            snake.pop_back();
            if(points.find(next) != points.end()) return -1;

            snake.push_front(next);
            points.insert(next);
        }

        return foodIdx;
    }
};



int main() {
    //Solution s;

}
