struct Node
{
    Node(char val)
    {
        value = val;
        parent = NULL;
        numOfChildren = 0;
    }

    char value;
    Node* parent;
    int numOfChildren;
};

class Solution {
public:
    bool isValidSerialization(std::string preorder) {
        std::vector<Node*> tree;
        tree.reserve(preorder.size());

        Node* parent = NULL;

        for(size_t i = 0, sz = preorder.size(); i < sz; i += 2)
        {
            Node* node = new Node(preorder[i]);
            if(i == 0)
            {
                node->parent = NULL;
            }
            else
            {
            	 if(!parent)
            		 return false;

            	 if(parent->numOfChildren == 2)
                 {
                     while(parent->numOfChildren == 2 && parent->parent)
                     {
                         parent = parent->parent;
                     }
                 }

                 if(!parent || parent->numOfChildren == 2)
                    return false;

                 node->parent = parent;
                 parent->numOfChildren += 1;
            }

            if(node->value != '#')
            {
                parent = node;
            }

            if(i == sz - 1)
            {
            	if(node->value != '#' || (parent && parent->numOfChildren != 2))
                    return false;
                return true;
            }
        }

        return true;
    }
};