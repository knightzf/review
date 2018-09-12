#include "header.h"

class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int startIdx = 0;
        int endIdx = 10000;
        
        while(startIdx <= endIdx)
        {
            int midIdx = (startIdx + endIdx) / 2;
            int t = reader.get(midIdx);
            if(t == target) {
                return midIdx;
            }
            else if(t > target) {
                endIdx = midIdx - 1;
            }
            else {
                startIdx = midIdx + 1;
            }
        }
        
        return -1;
    }
};

int main() {
    //Solution s;
}
