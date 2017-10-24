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

using namespace std;

class RangeModule {
public:
    RangeModule() {

    }

    void addRange(int left, int right)
    {
        auto leftIter = mData.lower_bound(left);
        auto rightIter = mData.upper_bound(right);

        if(leftIter != mData.begin())
        {
            --leftIter;
            if(leftIter->second < left)
            {
                ++leftIter;
            }
        }

        if(leftIter != rightIter)
        {
            left = std::min(left, leftIter->first);
            right = std::max(right, (--rightIter)->second);
            mData.erase(leftIter, ++rightIter);
        }

        mData[left] = right;
    }

    bool queryRange(int left, int right)
    {
        auto leftIter = mData.upper_bound(left);

        if(leftIter == mData.begin())
        {
            return false;
        }

        --leftIter;

        if(leftIter->second < right)
        {
            return false;
        }

        return true;
    }

    void removeRange(int left, int right)
    {
        auto leftIter = mData.upper_bound(left);
        auto rightIter = mData.upper_bound(right);

        if(leftIter != mData.begin())
        {
            --leftIter;
            if(leftIter->second < left)
            {
                ++leftIter;
            }
        }

        if(leftIter == rightIter)
        {
            return;
        }

        int newLeft = min(left, leftIter->first);
        int newRight = max(right, (--rightIter)->second);

        mData.erase(leftIter, ++rightIter);

        if (newLeft < left) mData[newLeft] = left;
        if (newRight > right) mData[right] = newRight;

    }

    void print()
    {
        for(auto i : mData)
        {
            std::cout<<i.first<<" "<<i.second<<"---";
        }
        std::cout<<"\n///////"<<std::endl;
    }

private:
    std::map<int, int> mData;
    typedef std::map<int, int>::iterator Iter;
};

int main()
{
    //Solution sol;
    RangeModule m;
    m.addRange(10, 180);
    m.addRange(150, 200);
    m.print();
    m.addRange(250, 500);
    m.print();
    std::cout<<m.queryRange(50, 100)<<std::endl;
    std::cout<<m.queryRange(180, 300)<<std::endl;
    std::cout<<m.queryRange(600, 1000)<<std::endl;
    m.removeRange(50, 150);
    m.print();
    std::cout<<m.queryRange(50, 100)<<std::endl;

}
