#include "header.h"

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        
        if(N == 1)
        {
            TreeNode* node = new TreeNode(0);
            res.push_back(node);
        }
        else
        {
            for(int i = 1; i < N - 1; i += 2)
            {
                vector<TreeNode*> leftV = allPossibleFBT(i);
                vector<TreeNode*> rightV = allPossibleFBT(N - 1 - i);
                for(int j = 0; j < leftV.size(); ++j)
                {
                    for(int k = 0; k < rightV.size(); ++k)
                    {
                        TreeNode* node = new TreeNode(0);
                        node->left = leftV[j];
                        node->right = rightV[k];
                        res.push_back(node);
                    }
                }
            }            
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.allPossibleFBT(2).size()<<endl;
}

