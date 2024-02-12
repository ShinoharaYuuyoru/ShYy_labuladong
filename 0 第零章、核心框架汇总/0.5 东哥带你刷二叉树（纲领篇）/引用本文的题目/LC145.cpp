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
    vector<int> postorderTraversal(TreeNode* root) {
        postorder_traverse(root);

        return postorder;
    }

   private:
    vector<int> postorder;

    void postorder_traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        postorder_traverse(root->left);
        postorder_traverse(root->right);
        postorder.push_back(root->val);
    }
};

// DP
class Solution {
   public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        vector<int> left_res = postorderTraversal(root->left);
        vector<int> right_res = postorderTraversal(root->right);
        res.insert(res.begin(), left_res.begin(), left_res.end());
        res.insert(res.end(), right_res.begin(), right_res.end());
        res.push_back(root->val);

        return res;
    }
};