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

class NumMatrix {
private:
    vector<SegmentTreeNode*> roots;
public:
    NumMatrix(vector<vector<int>> matrix) {
        for(const auto& nums : matrix)
        {
            SegmentTreeNode* root = new SegmentTreeNode(nums, 0, nums.size() - 1);
            roots.push_back(root);
        }
    }

    void update(int row, int col, int val) {
        update(roots[row], col, val);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for(int i = row1; i <= row2; ++i)
        {
            res += sum(roots[i], col1, col2);
        }

        return res;
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
}
