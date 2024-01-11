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

// Divide
class Solution {
   public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left_depth = minDepth(root->left);
        int right_depth = minDepth(root->right);
        if (left_depth == 0 && right_depth == 0) {
            return 1;
        } else {
            if (left_depth == 0) {
                return right_depth + 1;
            }
            if (right_depth == 0) {
                return left_depth + 1;
            }
        }
        return min(left_depth, right_depth) + 1;
    }
};

// Traverse
class Solution {
   public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        traverse(root, 1);
        return min_depth;
    }

   private:
    int min_depth = INT_MAX;
    void traverse(TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            min_depth = min(min_depth, depth);
            return;
        }

        traverse(root->left, depth + 1);
        traverse(root->right, depth + 1);
    }
};

// Level traverse, BFS.
class Solution {
   public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            curr_depth++;

            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                TreeNode* curr_node = q.front();
                q.pop();
                if (curr_node == nullptr) {
                    continue;
                }
                if (curr_node->left == nullptr && curr_node->right == nullptr) {
                    return curr_depth;
                }
                q.push(curr_node->left);
                q.push(curr_node->right);
            }
        }

        return curr_depth;
    }

   private:
    int curr_depth = 0;
};