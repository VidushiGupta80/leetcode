//N-ary Tree Preorder Traversal -> 06/04/2020 18:04
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    bool isLeaf(Node* root)
    {
        if(root->children.size() == 0)
            return true;
        return false;
    }
    void PreOrder (vector<int>& ans, Node* root)
    {
        if(isLeaf(root))
        {
            ans.push_back(root->val);
            return;
        }
        
        ans.push_back(root->val);
        for(int i = 0; i < root->children.size(); i++)
        {
            PreOrder(ans, root->children[i]);
        }
        
        return;
    }
    
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(root == NULL)
        {
            return ans;
        }
        
        PreOrder(ans, root);
        return ans;
    }
};
