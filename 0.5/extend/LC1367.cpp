/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == nullptr) {
            return true;
        }
        if (root == nullptr) {
            return false;
        }

        bool left_check = false, right_check = false;
        if (head->val == root->val) {
            if (check(head, root)) {
                return true;
            }
        }

        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }

   private:
    bool check(ListNode* head, TreeNode* root) {
        if (head == nullptr) {
            return true;
        }
        if (root == nullptr) {
            return false;
        }

        bool left_check = false, right_check = false;
        if (head->val == root->val) {
            left_check = check(head->next, root->left);
            right_check = check(head->next, root->right);
        }

        return left_check || right_check;
    }
};