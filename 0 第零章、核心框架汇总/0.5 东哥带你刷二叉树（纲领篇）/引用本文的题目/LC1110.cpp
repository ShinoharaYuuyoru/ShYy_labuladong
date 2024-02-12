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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto i : to_delete) {
            to_delete_set.insert(i);
        }

        do_delete(root, false);
        return res;
    }

   private:
    unordered_set<int> to_delete_set;
    vector<TreeNode*> res;

    TreeNode* do_delete(TreeNode* root, bool has_parent) {
        if (root == nullptr) {
            return nullptr;
        }

        bool need_delete = false;
        if (to_delete_set.find(root->val) != to_delete_set.end()) {
            need_delete = true;
        }
        if (!has_parent && !need_delete) {
            res.push_back(root);
        }

        root->left = do_delete(root->left, !need_delete);
        root->right = do_delete(root->right, !need_delete);

        if (need_delete == true) {
            return nullptr;
        } else {
            return root;
        }
    }
};