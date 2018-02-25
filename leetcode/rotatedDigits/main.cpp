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

class Solution {
public:
    int rotatedDigits(int N) {
        static vector<int> good;
        if(good.empty() || good.back() < N)
        {
            for(int i = (good.empty() ? 0 : good.back() + 1); i <= N; ++i)
            {
                if(isGoodNum(i))
                {
                    good.push_back(i);
                }
            }

            return good.size();
        }
        else
        {
            int startIdx = 0, endIdx = good.size() - 1;
            while(startIdx < endIdx - 1)
            {
                int mid = (startIdx + endIdx) / 2;
                if(good[mid] > N)
                {
                    endIdx = mid;
                }
                else if(good[mid] < N)
                {
                    startIdx = mid;
                }
                else
                {
                    return mid + 1;
                }
            }

            if(good[startIdx] > N)
            {
                return startIdx;
            }
            else if(good[startIdx] <= N && good[endIdx] > N)
            {
                return startIdx + 1;
            }
            else if(good[endIdx] <= N)
            {
                return endIdx + 1;
            }
        }
    }
private:
    bool isGoodNum(int n)
    {
        int diffCount = 0;
        while(n != 0)
        {
            int t = n % 10;
            if(t == 0 || t == 1 || t == 8)
            {
            }
            else if(t == 2 || t == 5 || t == 6 || t == 9)
            {
                ++diffCount;
            }
            else
            {
                return false;
            }
            n = n / 10;
        }

        return diffCount != 0;
    }
};

int main() {
    Solution s;
    std::cout<<s.rotatedDigits(1)<<std::endl;
    std::cout<<s.rotatedDigits(10)<<std::endl;
    std::cout<<s.rotatedDigits(8)<<std::endl;
    std::cout<<s.rotatedDigits(9)<<std::endl;
}
