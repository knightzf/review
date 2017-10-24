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
        if(mData.empty())
        {
            mData.insert(std::make_pair(left, right));
            return;
        }

        auto iter = mData.lower_bound(left);
        if(iter != mData.end())
        {
            if(iter == mData.begin())
            {
                if(right < iter->first)
                {
                    mData.insert(std::make_pair(left, right));
                }
                else
                {
                    std::vector<std::map<int, int>::iterator> iterV;
                    iterV.push_back(iter);

                    auto tIter = iter;
                    while(true)
                    {
                       ++tIter;
                       if(tIter == mData.end() || tIter->first > right)
                       {
                           break;
                       }

                       iterV.push_back(tIter);
                    }

                    int newRight = iterV.back()->second;
                    for(auto ii : iterV)
                    {
                        mData.erase(ii);
                    }

                    mData.insert(std::make_pair(left, newRight));
                }
            }
            else
            {
                auto prevIter = iter;
                --prevIter;
                if(prevIter->second < left && iter->first > right)
                {
                    mData.insert(std::make_pair(left, right));
                }
                else
                {
                    std::vector<std::map<int, int>::iterator> prevIterV;
                    if(prevIter->second >= left)
                    {
                        prevIterV.push_back(prevIter);
                    }

                    bool breakNext = false;
                    while(true)
                    {
                        --prevIter;

                        if(breakNext || prevIter->second < left)
                        {
                            break;
                        }

                        if(prevIter == mData.begin())
                        {
                            bool breakNext = true;
                        }

                        prevIterV.push_back(prevIter);
                    }

                    std::vector<std::map<int, int>::iterator> nextIterV;
                    if(iter->first <= right)
                    {
                        nextIterV.push_back(iter);
                    }

                    auto tIter = iter;
                    while(true)
                    {
                        ++tIter;

                        if(tIter == mData.end() || tIter->first > right)
                        {
                            break;
                        }

                        nextIterV.push_back(tIter);
                    }

                    int newLeft = prevIterV.empty() ? left : prevIterV.back()->first;
                    int newRight = nextIterV.empty() ? right : nextIterV.back()->second;

                    for(auto ii : prevIterV)
                    {
                        mData.erase(ii);
                    }

                    for(auto ii : nextIterV)
                    {
                        mData.erase(ii);
                    }

                    mData.insert(std::make_pair(newLeft, newRight));
                }
            }
        }
        else
        {
            auto lastIter = mData.rbegin();
            if(lastIter->second >= left)
            {
                if(lastIter->second < right)
                {
                    int start = lastIter->first;
                    mData.erase(--(lastIter.base()));
                    mData.insert(std::make_pair(start, right));
                }
            }
            else
            {
                mData.insert(std::make_pair(left, right));
            }
        }
    }

    bool queryRange(int left, int right)
    {
        if(mData.empty())
        {
            return false;
        }

        auto iter = mData.lower_bound(left);

        if(iter != mData.end())
        {
            auto tIter = iter;
            while(true)
            {
                if(tIter->first <= left)
                {
                    if(tIter->second >= right)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }

                if(tIter == mData.begin() || tIter->second < left)
                {
                    return false;
                }

                --tIter;
            }
        }
        else
        {
            for(auto ii = mData.begin(); ii != mData.end(); ++ii)
            {
                if(ii->first <= left && ii->second >= right)
                {
                    return true;
                }
            }

            return false;
        }
    }

    void removeRange(int left, int right)
    {
        if(mData.empty())
        {
            return;
        }

        auto iter = mData.lower_bound(left);

        if(iter != mData.end())
        {
            std::vector<std::map<int, int>::iterator> delVec;
            std::vector<std::map<int, int>::iterator> addVec;

            auto prevIter = iter;
            --prevIter;

            while(true)
            {
                if(prevIter->first >= left)
                {
                    delVec.push_back(prevIter);
                }
                else
                {

                }

                if(prevIter == mData.begin() || prevIter->second <= left)
                {
                    break;
                }

                --prevIter;
            }

            auto nextIter = iter;
            while(true)
            {
                if(nextIter == mData.end() || )
                {
                    break;
                }

                ++nextIter;
            }
        }
        else
        {
            std::vector<std::map<int, int>::iterator> delVec;

            for(auto ii = mData.begin(); ii != mData.end(); ++ii)
            {
                if(ii->first <= left)
                {
                    if(ii->second >= right)
                    {
                        int leftStart = ii->first;
                        int leftEnd = left;

                        int rightStart = right;
                        int rightEnd = ii->second;

                        mData.erase(ii);

                        for(auto jj : delVec)
                        {
                            mData.erase(jj);
                        }

                        if(leftStart != leftEnd)
                        {
                            mData.insert(std::make_pair(leftStart, leftEnd));
                        }

                        if(rightStart != rightEnd)
                        {
                            mData.insert(std::make_pair(rightStart, rightEnd));
                        }

                        break;
                    }
                    else
                    {
                        delVec.push_back(ii);
                        auto tIter = ii;
                        ++tIter;
                        if(right > tIter->first)
                        {
                            left = tIter->first;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
        }
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
};

int main()
{
    //Solution sol;
    RangeModule m;
    m.addRange(5, 7);
    m.addRange(6, 9);
    m.addRange(2, 7);
    m.print();
    m.removeRange(3, 10);
    m.print();
    m.removeRange(1, 8);
    m.print();
    m.removeRange(1, 10);
    m.print();
}
