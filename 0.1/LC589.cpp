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
   public:
    vector<int> preorder(Node* root) {
        traverse(root);

        return result;
    }

    void traverse(Node* root) {
        vector<int> curr;
        if (root == nullptr) {
            return;
        }

        result.push_back(root->val);
        vector<Node*> root_children = root->children;
        for (auto i = root_children.begin(); i < root_children.end(); i++) {
            traverse(*i);
        }
    }

   private:
    vector<int> result;
};

class Solution {
   public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        res.push_back(root->val);
        for (Node* child : root->children) {
            vector<int> child_preorder = preorder(child);
            res.insert(res.end(), child_preorder.begin(), child_preorder.end());
        }

        return res;
    }
};