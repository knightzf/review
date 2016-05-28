struct Node
{
    Node(int val_)
    {
        value = val_;
        maxPath = 0;
        left = NULL;
        right = NULL;
        up = NULL;
        down = NULL;
    }
    int value;
    int maxPath;
    Node* left;
    Node* right;
    Node* up;
    Node* down;
};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return 0;
            
        std::vector<std::vector<Node*> > nodeMatrix;
        
        size_t rows = matrix.size();
        size_t columns = matrix[0].size();
        
        for(size_t i = 0; i < rows; ++i)
        {
            std::vector<Node*> row;
            for(size_t j = 0; j < columns; ++j)
            {
                row.push_back(new Node(matrix[i][j]));
            }
            nodeMatrix.push_back(row);
        }
        
        for(size_t i = 0; i < rows; ++i)
        {
            for(size_t j = 0; j < columns; ++j)
            {
                if(i != 0)
                {
                    nodeMatrix[i][j]->up = nodeMatrix[i-1][j];
                }
                
                if(i != rows - 1)
                {
                    nodeMatrix[i][j]->down = nodeMatrix[i + 1][j];
                }
                
                if(j != 0)
                {
                    nodeMatrix[i][j]->left = nodeMatrix[i][j - 1];
                }
                
                if(j != columns - 1)
                {
                    nodeMatrix[i][j]->right = nodeMatrix[i][j + 1];
                }
            }
        }
        
        for(size_t i = 0; i < rows; ++i)
        {
            for(size_t j = 0; j < columns; ++j)
            {
                nodeMatrix[i][j]->maxPath = findMaxPath(nodeMatrix[i][j]);
            }
        }
        
        int maxPath = 0;
        for(size_t i = 0; i < rows; ++i)
        {
            for(size_t j = 0; j < columns; ++j)
            {
                if(nodeMatrix[i][j]->maxPath > maxPath)
                {
                    maxPath = nodeMatrix[i][j]->maxPath;
                }
            }
        }
        
        return maxPath;
    }
    
    int findMaxPath(Node* node)
    {
        static std::map<Node*, int> pathMap;
        
        if(pathMap.find(node) != pathMap.end())
        {
            return pathMap[node];
        }
        
        int leftPath = node->left ? (node->left->value > node->value ? findMaxPath(node->left) : 0) : 0;
        int rightPath = node->right ? (node->right->value > node->value ? findMaxPath(node->right) : 0) : 0;
        int upPath = node->up ? (node->up->value > node->value ? findMaxPath(node->up) : 0) : 0;
        int downPath = node->down ? (node->down->value > node->value ? findMaxPath(node->down) : 0) : 0;
        
        int maxPath = std::max(std::max(leftPath, rightPath), std::max(upPath, downPath)) + 1;
        
        pathMap[node] = maxPath;
        
        return maxPath;
    }
};