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
#include <iterator>

using namespace std;

class Heap
{
public:
    Heap(const std::vector<int>& v)
    {
        heap.reserve(v.size());
        for(int num : v)
        {
            heapify(num);
        }
    }

    void heapify(int num)
    {
        int idx = heap.size();
        heap.emplace_back(num);

        int pIdx = parentIdx(idx);
        while(idx != 0 && heap[pIdx] < heap[idx])
        {
            std::swap(heap[pIdx], heap[idx]);
            idx = pIdx;
            pIdx = parentIdx(idx);
        }
    }

    void print()
    {
        for(int n : heap)
        {
            std::cout<<n<<" ";
        }
        std::cout<<std::endl;
    }

    int getMax()
    {
        if(heap.empty()) return 0;

        int t = heap[0];
        std::swap(heap[0], heap.back());

        heap.pop_back();

        int idx = 0;
        int leftIdx = 2 * idx + 1;
        int rightIdx = 2 * idx + 2;
        int n = heap.size();

        while(idx < n && (leftIdx < n || rightIdx < n))
        {
            int maxIdx = idx;

            if(leftIdx < n && heap[idx] < heap[leftIdx])
            {
                maxIdx = leftIdx;
            }

            if(rightIdx < n && heap[idx] < heap[rightIdx])
            {
                maxIdx = rightIdx;
            }

            if(maxIdx != idx)
            {
                std::swap(heap[idx], heap[maxIdx]);
                idx = maxIdx;
            }
            else
            {
                break;
            }

            leftIdx = 2 * idx + 1;
            rightIdx = 2 * idx + 2;
        }

        return t;
    }

private:
    int parentIdx(int idx)
    {
        if(idx == 0) return 0;
        if(idx % 2 == 0) return (idx - 2) / 2;
        return (idx - 1) / 2;
    }

private:
    vector<int> heap;
};

int main() {
    //Solution s;

    vector<int> a{2, 3, 5, 1, 4};
    Heap h(a);
    h.print();
    for(int i = 0; i < 5; ++i)
        std::cout<<h.getMax()<<std::endl;
    //h.print();
}
