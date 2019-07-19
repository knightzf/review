#include "header.h"

class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if(!root) return "";
        string res = "[";
        res += to_string(root->val);
        for(int i = 0, n = root->children.size(); i < n; ++i) {
            res += ' ' + serialize(root->children[i]);
        }
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        Node* res = nullptr;
        stack<Node*> s;
        int num = 0;
        for(char c : data) {
            switch(c){
                case '[':
                    s.push(nullptr);
                    break;
                case ']':
                case ' ':
                {
                    if(!s.top()) {
                        s.top() = new Node();
                        s.top()->val = num;
                        num = 0;
                    }
                    if(c == ']') {
                        if(s.size() > 1) {
                            Node* t = s.top();
                            s.pop();
                            s.top()->children.push_back(t);
                        } else res = s.top();
                    }
                    break;
                }
                default: num = num * 10 + (c - '0'); break;
            }
        }
        return res;
    }
};

int main()
{
    //Solution s;
}