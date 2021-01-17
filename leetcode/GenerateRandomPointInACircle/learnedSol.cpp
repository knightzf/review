class Solution {
private:
    double x, y, r;
public:
    Solution(double radius, double x_center, double y_center) : r(radius), x(x_center), y(y_center){
    }
    
    vector<double> randPoint() {
        double dist = sqrt((double) rand() / RAND_MAX) * r;
        double deg = (double) rand() / RAND_MAX * 2 * M_PI;
        return {x + cos(deg) * dist, y + sin(deg) * dist};
    }
};
