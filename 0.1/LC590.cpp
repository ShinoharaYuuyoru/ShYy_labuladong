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
    vector<int> postorder(Node* root) {
        traverse(root);

        return result;
    }

   private:
    vector<int> result;

    void traverse(Node* root) {
        if (root == nullptr) {
            return;
        }

        for (auto child : root->children) {
            traverse(child);
        }
        result.push_back(root->val);
    }
};

class Solution {
   public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        for (Node* child : root->children) {
            vector<int> child_postorder = postorder(child);
            res.insert(res.end(), child_postorder.begin(), child_postorder.end());
        }
        res.push_back(root->val);

        return res;
    }
};