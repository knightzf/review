#include "header.h"

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    vector<Point> outerTrees(vector<Point>& points) {
        int n = points.size();
        int minX = INT_MAX;
        for(int i = 0; i < n; ++i)
        {
            minX = min(minX, points[i].x);
        }

        Point start(minX, INT_MAX);
        for(int i = 0; i < n; ++i)
        {
            if(points[i].x == minX)
            {
                start.y = min(start.y, points[i].y);
            }
        }

        /*for(auto p : points)
        {
            if(p.x != start.x)
            cout<<(p.y - start.y) / (p.x - start.x)<<endl;
        }*/
        sort(points.begin(), points.end(), [&](const auto& a, const auto& b){
                if(a.x == start.x && b.x > start.x) return true;
                if(b.x == start.x && a.x > start.x) return false;
                if(a.x == start.x && b.x == start.x) return a.y < b.y;
                if((a.y - start.y) * (b.x - start.x) == (b.y - start.y) * (a.x - start.x))
                {
                    if(float(a.y - start.y) / (a.x - start.x) > 0)
                    {
                        return (a.y - start.y) * (a.y - start.y) + (a.x - start.x) * (a.x - start.x) <
                        (b.y - start.y) * (b.y - start.y) + (b.x - start.x) * (b.x - start.x);
                    }
                    else
                    {
                        return (a.y - start.y) * (a.y - start.y) + (a.x - start.x) * (a.x - start.x) >
                        (b.y - start.y) * (b.y - start.y) + (b.x - start.x) * (b.x - start.x);
                    }
                }

                return float(a.y - start.y) / (a.x - start.x) > float(b.y - start.y) / (b.x - start.x);
             });
        //for(auto p : points)
        //    cout<<"p "<<p.x<<" "<<p.y<<endl;
        vector<Point> v;
        for(int i = 0; i <= n; ++i)
        {
            if(i < 2 && i < n)
            {
                v.push_back(points[i]);
            }
            else
            {
                const Point& c = points[i % n];
                while(v.size() >= 2)
                {
                    const Point& a = v[v.size() - 2];
                    const Point& b = v[v.size() - 1];

                    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
                    //std::cout<<i<<" "<<c.x<<" "<<c.y<<" "<<val<<endl;
                    if(val >= 0)
                    {
                        break;
                    }
                    v.pop_back();
                }

                if(i != n)
                {
                    //cout<<"push back"<<endl;
                    v.push_back(c);
                }
            }
        }
        return v;
    }
};

int main()
{
    Solution s;
    //vector<Point> a{{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}};
    //vector<Point> a{{1,2},{2,2},{4,2}};
    //vector<Point> a{{0,2},{1,1},{2,2},{2,4},{4,2},{3,3}};
    //vector<Point> a{{3,0},{4,0},{5,0},{6,1},{7,2},{7,3},{7,4},{6,5},{5,5},{4,5},{3,5},{2,5},{1,4},{1,3},{1,2},{2,1},{4,2},{0,3}};
    //vector<Point> a{{5,5},{4,8},{1,3},{5,9},{3,0},{0,4},{3,2},{8,9},{9,3}};
    vector<Point> a{{1, 5}};
    const auto& r = s.outerTrees(a);
    for(const auto& p : r)
        cout<<p.x<<" "<<p.y<<endl;
}
