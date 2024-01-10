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
// Level traverse
class Solution {
   public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<TreeNode*> v;
            while (!q.empty()) {
                v.push_back(q.front());
                q.pop();
            }
            for (int i = 0, j = v.size() - 1; i < j; i++, j--) {
                if (v[i] == nullptr && v[j] != nullptr ||
                    v[i] != nullptr && v[j] == nullptr) {
                    return false;
                } else if (v[i] != nullptr && v[j] != nullptr &&
                           v[i]->val != v[j]->val) {
                    return false;
                }
            }
            for (int i = 0; i < v.size(); i++) {
                if (v[i] != nullptr) {
                    q.push(v[i]->left);
                    q.push(v[i]->right);
                }
            }
        }
        return true;
    }
};

// Divide
class Solution {
   public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return check(root->left, root->right);
    }

    bool check(TreeNode* left, TreeNode* right) {
        if (left == nullptr || right == nullptr) {
            return left == right;
        }

        return (left->val == right->val) &&
               check(left->left, right->right) &&
               check(left->right, right->left);
    }
};