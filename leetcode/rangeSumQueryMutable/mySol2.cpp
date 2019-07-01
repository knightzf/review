#include "header.h"

struct RangeNode {
    RangeNode* parent;
    RangeNode* left;
    RangeNode* right;
    int startIdx;
    int endIdx;
    int sum;
};

class NumArray {
private:
    RangeNode* root;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }

        function<RangeNode*(RangeNode*, int, int)> create = [&]
        (RangeNode* p, int startIdx, int endIdx) {
            if(startIdx > endIdx) return static_cast<RangeNode*>(0);
            RangeNode* node = new RangeNode{
                p, nullptr, nullptr, startIdx, endIdx, sum[endIdx + 1] - sum[startIdx]};
            if(startIdx != endIdx) {
                int m = (startIdx + endIdx) / 2;
                node->left = create(node, startIdx, m);
                node->right = create(node, m + 1, endIdx);
            }
            return node;
        };

        root = create(nullptr, 0, n - 1);
    }

    void update(int i, int val) {
        function<void(RangeNode*)> upd = [&](RangeNode* node) {
            if(!node) return;
            if(node->startIdx == i && node->endIdx == i) {
                int diff = val - node->sum;
                while(node) {
                    node->sum += diff;
                    node = node->parent;
                }
            } else {
                int m = (node->startIdx + node->endIdx) / 2;
                if(i <= m) upd(node->left);
                else upd(node->right);
            }
        };
        upd(root);
    }

    int sumRange(int i, int j) {
        function<int(RangeNode*, int, int)> sum = [&]
        (RangeNode* node, int i, int j) {
            if(!node) return 0;
            i = max(node->startIdx, i), j = min(node->endIdx, j);
            if(i == node->startIdx && j == node->endIdx) return node->sum;
            if(j <= m) return sum(node->left, i, j);
            if(i > m) return sum(node->right, i, j);
            return sum(node->left, i, j) + sum(node->right, i, j);
        };
        return sum(root, i, j);
    }
};

int main()
{
    //Solution s;
}