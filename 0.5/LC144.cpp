/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Traverse
class Solution {
   public:
    vector<int> preorderTraversal(TreeNode* root) {
        pre_order_traverse(root);
        return pre_order;
    }

   private:
    vector<int> pre_order;
    void pre_order_traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        pre_order.push_back(root->val);
        pre_order_traverse(root->left);
        pre_order_traverse(root->right);
    }
};

// Divide
class Solution {
   public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> pre_order;
        pre_order.push_back(root->val);
        vector<int> left_pre_order = preorderTraversal(root->left);
        pre_order.insert(pre_order.end(), left_pre_order.begin(), left_pre_order.end());
        vector<int> right_pre_order = preorderTraversal(root->right);
        pre_order.insert(pre_order.end(), right_pre_order.begin(), right_pre_order.end());

        return pre_order;
    }
};