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
    struct TreeNode
    {
        TreeNode(int v, int s) : val(v), smallerCount(s)
        {

        }
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        int val;
        int smallerCount;
    };

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};

        vector<int> res(n, 0);
        TreeNode* root = nullptr;
        for(int i = n - 1; i >= 0; --i)
        {
            root = update(root, nums[i], i, 0, res);
        }

        return res;
    }

private:
    TreeNode* update(TreeNode* root, int val, int idx, int smallerCount, vector<int>& res)
    {
        if(root == nullptr)
        {
            root = new TreeNode(val, 0);
            res[idx] = smallerCount;
        }
        else if(root->val > val)
        {
            ++root->smallerCount;
            root->left = update(root->left, val, idx, smallerCount, res);
        }
        else
        {
            root->right = update(root->right, val, idx, smallerCount + root->smallerCount + (root->val < val ? 1 : 0), res);
        }

        return root;
    }
};

int main() {
    Solution s;
    vector<int> a{5,2,6,1};
    const auto& r = s.countSmaller(a);
    for(int i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
