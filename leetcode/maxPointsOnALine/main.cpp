#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
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

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct Slope
{
    int x = 0;
    int y = 0;
    bool valid = false;
    Slope() = default;
    Slope(int x_, int y_) : x(x_), y(y_), valid(true) {}

    bool operator< (const Slope& rhs) const
    {
       return std::tie(x, y, valid) < std::tie(rhs.x, rhs.y, rhs.valid);
    }
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();

        if(n == 0)
        {
            return 0;
        }

        if(n == 1)
        {
            return 1;
        }

        std::vector<std::vector<Slope>> slope(n, vector<Slope>(n, Slope()));

        int maxPoints = 0;

        for(int i = 0; i < n; ++i)
        {
            std::map<Slope, int> countMap;
            int localMax = 0;
            for(int j = 0; j < n; ++j)
            {
                //std::cout<<i<<" "<<j<<std::endl;
                if(j < i)
                {
                    slope[i][j] = slope[j][i];
                }
                else if(j > i)
                {
                    if(points[i].y == points[j].y && points[i].x == points[j].x)
                    {
                        slope[i][j] = Slope(INT_MAX, INT_MAX);
                    }
                    else if(points[i].y == points[j].y)
                    {
                        slope[i][j] = Slope(INT_MAX, 0);
                    }
                    else if(points[i].x == points[j].x)
                    {
                        slope[i][j] = Slope(0, INT_MAX);
                    }
                    else
                    {
                        int yDiff = points[i].y - points[j].y;
                        int xDiff = points[i].x - points[j].x;
                        if(yDiff / xDiff < 0)
                        {
                            yDiff = std::abs(yDiff);
                            xDiff = -std::abs(xDiff);
                        }
                        if(yDiff < 0 && xDiff < 0)
                        {
                            yDiff = std::abs(yDiff);
                            xDiff = std::abs(xDiff);
                        }
                        //std::cout<<xDiff<<" | "<<yDiff<<std::endl;
                        int gcd = getGcd(std::abs(xDiff), std::abs(yDiff));
                        slope[i][j] = Slope(xDiff/gcd, yDiff/gcd);
                    }
                }

                if(slope[i][j].valid)
                {
                    std::cout<<i<<" "<<j<<" "<<slope[i][j].x<<" "<<slope[i][j].y<<std::endl;
                    if(countMap.find(slope[i][j]) == countMap.end())
                    {
                        countMap[slope[i][j]] = 2;
                    }
                    else
                    {
                        ++countMap[slope[i][j]];
                    }

                    //std::cout<<i<<" "<<j<<" "<<countMap[slope[i][j]]<<std::endl;

                    if(slope[i][j].x != INT_MAX || slope[i][j].y != INT_MAX)
                        localMax = countMap[slope[i][j]] > localMax ? countMap[slope[i][j]] : localMax;
                }
            }

            if(countMap.find(Slope(INT_MAX, INT_MAX)) != countMap.end())
            {
                int samePointCount = countMap[Slope(INT_MAX, INT_MAX)] - 1;

                if(localMax)
                {
                    localMax += samePointCount;
                }
                else
                {
                    localMax = samePointCount + 1;
                }
            }

            maxPoints = localMax > maxPoints ? localMax : maxPoints;
        }

        return maxPoints;
    }
private:
    int getGcd(int a, int b)
    {
        if(a < b)
        {
            std::swap(a, b);
        }

        if(b == 0) return a;
        return getGcd(b, a % b);
    }
};


int main()
{
    Solution s;
    /*std::vector<Point> a{Point(84,250), Point(0, 0), Point(1,0), Point(0,-70), Point(0,-70), Point(1,-1),
        Point(21,10), Point(42,90), Point(-42,-230)
    };*/
    //std::vector<Point> a{Point(0,0), Point(1,1), Point(0,0)};
    //std::vector<Point> a{Point(0,0), Point(0,0)};
    //std::vector<Point> a{Point(0,0), Point(1,0)};
    std::vector<Point> a{Point(0,9),Point(138,429),Point(115,359),Point(115,359),Point(-30,-102),Point(230,709),Point(-150,-686),Point(-135,-613),Point(-60,-248),Point(-161,-481),Point(207,639),Point(23,79),Point(-230,-691),Point(-115,-341),Point(92,289),Point(60,336),Point(-105,-467),Point(135,701),Point(-90,-394),Point(-184,-551),Point(150,774)};
    std::cout<<s.maxPoints(a)<<std::endl;

}
