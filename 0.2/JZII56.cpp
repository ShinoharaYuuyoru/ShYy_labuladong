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
class Solution {
   public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder = inorder_traverse(root);

        int left_p = 0;
        int right_p = inorder.size() - 1;
        while (left_p < right_p) {
            int sum = inorder[left_p] + inorder[right_p];
            if (sum < k) {
                left_p++;
            } else if (sum == k) {
                return true;
            } else {
                right_p--;
            }
        }
        return false;
    }

   private:
    vector<int> inorder_traverse(TreeNode* root) {
        vector<int> curr_inorder;
        if (root == nullptr) {
            return curr_inorder;
        }

        vector<int> left_inorder = inorder_traverse(root->left);
        curr_inorder.insert(curr_inorder.end(), left_inorder.begin(), left_inorder.end());
        curr_inorder.push_back(root->val);
        vector<int> right_inorder = inorder_traverse(root->right);
        curr_inorder.insert(curr_inorder.end(), right_inorder.begin(), right_inorder.end());

        return curr_inorder;
    }
};