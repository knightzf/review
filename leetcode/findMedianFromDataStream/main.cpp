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

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        //std::cout<<"num "<<num<<std::endl;
        if(m.empty())
        {
            ++m[num];
            mid = m.begin();
            ++leftCount;
        }
        else
        {
            ++m[num];
            if(num <= mid->first)
            {
                ++leftCount;
                //std::cout<<"left "<<leftCount<<" "<<rightCount<<std::endl;
                if(leftCount - mid->second >= (leftCount + rightCount) / 2.0)
                {
                    leftCount -= mid->second;
                    rightCount += mid->second;
                    --mid;
                }
            }
            else if(num > mid->first)
            {
                ++rightCount;
                if(rightCount > (leftCount + rightCount) / 2)
                {
                    ++mid;
                    leftCount += mid->second;
                    rightCount -= mid->second;
                }
            }
        }

        //std::cout<<mid->first<<" "<<mid->second<<" "<<leftCount<<" "<<rightCount<<std::endl;
    }

    double findMedian() {
        //std::cout<<leftCount<<" "<<rightCount<<std::endl;
        if(m.empty())
        {
            throw std::bad_alloc();
        }

        if(leftCount == rightCount)
        {
            auto p = mid; ++p;
            return (mid->first + p->first) / 2.0;
        }
        else if(leftCount > rightCount)
        {
            return mid->first;
        }
    }

private:
    std::map<int, int> m;
    std::map<int, int>::iterator mid = m.end();
    int leftCount = 0;
    int rightCount = 0;
};

int main() {
    //Solution s;

    /*{
        MedianFinder f;
        f.addNum(2);f.addNum(3);f.addNum(4);
        std::cout<<f.findMedian()<<std::endl;
    }
    {
        MedianFinder f;
        f.addNum(2);f.addNum(3);
        std::cout<<f.findMedian()<<std::endl;
    }
    {
        MedianFinder f;
        f.addNum(-1);f.addNum(-2);//f.addNum(-3);f.addNum(-4);f.addNum(-5);
        std::cout<<f.findMedian()<<std::endl;
    }*/
    {
        MedianFinder f;
        f.addNum(6);f.addNum(10);f.addNum(2);f.addNum(6);f.addNum(5);f.addNum(0);f.addNum(6);f.addNum(3);
        std::cout<<f.findMedian()<<std::endl;
    }

}
