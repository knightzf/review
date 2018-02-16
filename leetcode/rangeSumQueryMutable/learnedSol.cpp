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

struct SegmentTreeNode
{
    SegmentTreeNode(const vector<int>& nums, int start, int end)
    {
        if(start > end) return;
        range = std::make_pair(start, end);
        isLeaf = start == end;
        left = isLeaf ? nullptr : new SegmentTreeNode(nums, start, (start + end) / 2);
        right = isLeaf ? nullptr : new SegmentTreeNode(nums, (start + end) / 2 + 1, end);
        sum = isLeaf ? nums[start] : left->sum + right->sum;
    }

    std::pair<int, int> range;
    bool isLeaf;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    int sum;
};

class NumArray {
private:
    SegmentTreeNode* root;
public:
    NumArray(vector<int> nums) {
        root = new SegmentTreeNode(nums, 0, nums.size() - 1);
    }

    void update(int i, int val) {
        update(root, i, val);
    }

    int sumRange(int i, int j) {
        return sum(root, i, j);
    }
private:
    void update(SegmentTreeNode* root, int i, int val)
    {
        if(root->isLeaf)
        {
            root->sum = val;
        }
        else
        {
            int mid = (root->range.first + root->range.second) / 2;
            if(i <= mid)
            {
                update(root->left, i, val);
            }
            else
            {
                update(root->right, i, val);
            }

            root->sum = root->left->sum + root->right->sum;
        }
    }

    int sum(SegmentTreeNode* root, int i, int j)
    {
        if(root == nullptr) return 0;
        else if(root->isLeaf) return root->sum;

        if(i <= root->range.first && j >= root->range.second)
        {
            return root->sum;
        }
        else
        {
            int mid = (root->range.first + root->range.second) / 2;
            if(j <= mid)
            {
                return sum(root->left, i, j);
            }
            else if(i > mid)
            {
                return sum(root->right, i, j);
            }
            else
            {
                return sum(root->left, i, j) + sum(root->right, i, j);
            }
        }
    }
};


int main() {
    //Solution s;

    /*vector<int> t{1, 3, 5, 7, 9, 11};
    NumArray a(t);
    std::cout<<a.sumRange(2, 3)<<std::endl;*/

    vector<int> t{9, -8};
    NumArray a(t);
    a.update(0, 3);
    std::cout<<a.sumRange(1, 1)<<std::endl;
    std::cout<<a.sumRange(0, 1)<<std::endl;
    a.update(1, -3);
    //a.update(0, -4);
    std::cout<<a.sumRange(0, 1)<<std::endl;
}
