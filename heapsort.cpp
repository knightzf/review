// It is not obvious that heapify has the time complexity of O(n) instead of O(n * ln(n))
// https://www.happycoders.eu/algorithms/heapsort/#Time_Complexity_of_the_heapify_Method
#include <iostream>
#include <vector>

using namespace std;

class Heap {
public:
    explicit Heap(const std::vector<int>& v) : v_(v), size_(v.size()) {
        for(int i = size_ / 2 - 1; i >= 0; --i) {
            siftDown(i);            
        }
    }
    
    void siftDown(int parentIdx) {
        while(true) {
            int largestIdx = parentIdx;
            int leftChildIdx = 2 * parentIdx + 1, rightChildIdx = 2 * parentIdx + 2;
            if(leftChildIdx < size_ && v_[largestIdx] < v_[leftChildIdx]) {
                largestIdx = leftChildIdx;
            }
            if(rightChildIdx < size_ && v_[largestIdx] < v_[rightChildIdx]) {
                largestIdx = rightChildIdx;
            }
            if(largestIdx != parentIdx) {
                swap(v_[parentIdx], v_[largestIdx]);
                parentIdx = largestIdx;
                continue;
            }
            break;
        }
    }
    
    int pop() {
        int val = v_[0];
        swap(v_[0], v_[size_ - 1]);
        --size_;
        siftDown(0);
        return val;
    }
    
    bool empty() {
        return size_ == 0;
    }
    
private:    
    std::vector<int> v_;
    int size_;
};

int main() {
    vector<int> a{2, 4, 1, 9, 5, 3, 2};
    Heap h(a);
    while(!h.empty()) {
        cout << h.pop() << " ";
    }
    cout << endl;
}
