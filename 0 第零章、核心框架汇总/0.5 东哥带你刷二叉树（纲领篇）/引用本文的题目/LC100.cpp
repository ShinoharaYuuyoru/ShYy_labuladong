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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        traverse(p, q);
        return is_same;
    }

   private:
    bool is_same = true;

    void traverse(TreeNode* p, TreeNode* q) {
        if (is_same == false) {
            return;
        }

        if (p == nullptr && q != nullptr ||
            p != nullptr && q == nullptr) {
            is_same = false;
            return;
        } else if (p == nullptr && q == nullptr) {
            return;
        } else {
            if (p->val != q->val) {
                is_same = false;
                return;
            } else {
                traverse(p->left, q->left);
                traverse(p->right, q->right);
            }
        }
    }
};

// Divide
class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p != nullptr && q == nullptr ||
                   p == nullptr && q != nullptr) {
            return false;
        } else {
            if (p->val != q->val) {
                return false;
            }
        }

        bool left_is_same = isSameTree(p->left, q->left);
        bool right_is_same = isSameTree(p->right, q->right);
        if (left_is_same == true && right_is_same == true) {
            return true;
        } else {
            return false;
        }
    }
};