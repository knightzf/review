#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        std::vector<int> result;
        
        int size = arr.size();        
        
        if(x <= arr[0])
        {
            for(int i = 0; i < k; ++i)
            {
                if(i == arr.size())
                    break;
                else
                    result.push_back(arr[i]);
            }
            
            return result;
        }
        else if(x >= arr[arr.size() - 1])
        {
            for(int i = size - k; i < size; ++i)
            {
                if(i < 0)
                    continue;
                else
                    result.push_back(arr[i]);
            }
            
            return result;
        }
        
        double pos;
        size_t start = 0;
        size_t end = arr.size() - 1;
        
        while(true)
        {
            size_t mid = (start + end) / 2;
            if(arr[mid] == x)
            {
                pos = mid;
                break;
            }
            else
            {
                if(mid == start || mid == end)
                {
                    pos = (start + end)/2.0;
                    break;
                }
                else if(arr[mid] > x)
                {
                    end = mid;
                }
                else if(arr[mid] < x)
                {
                    start = mid;
                }                    
            }
        }
                
        std::multiset<int> tempSet;
        int left = 0;
        int right = 0;
        for(int i = 0; i < k; ++i)
        {
            if(i == 0)
            {
                if(pos == int(pos))
                {
                    tempSet.insert(arr[pos]);
                    left = pos - 1;
                    right = pos + 1;
                    continue;
                }
                else
                {
                    left = std::floor(pos);
                    right = std::ceil(pos);
                }
            }
            
            if(left < 0 && right > size - 1)
                break;
            else if(left < 0 && right < size)
            {
                tempSet.insert(arr[right]);
                ++right;
            }
            else if(left >=0 && right > size - 1)
            {
                tempSet.insert(arr[left]);
                --left;
            }
            else
            {
                if(x - arr[left] <= arr[right] - x)
                {
                    tempSet.insert(arr[left]);
                    --left;
                }
                else 
                {
                    tempSet.insert(arr[right]);
                    ++right;
                }
            }
        }
        
        std::copy(tempSet.begin(), tempSet.end(), std::back_inserter(result));

        return result;
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{0,1,1,1,2,3,6,7,8,9};
    sol.findClosestElements(a, 9, 4);
	return 0;
}