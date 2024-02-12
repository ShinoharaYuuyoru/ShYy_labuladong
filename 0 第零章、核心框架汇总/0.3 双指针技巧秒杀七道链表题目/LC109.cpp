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

// BST in-order traverse, which is the ascending order.
class Solution {
   public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        for (ListNode* p = head; p != nullptr; p = p->next) {
            len++;
        }

        curr = head;
        return build_tree(0, len - 1);
    }

    TreeNode* build_tree(int left_margin, int right_margin) {
        if (left_margin > right_margin) {
            return nullptr;
        }

        int mid = (left_margin + right_margin) / 2;
        TreeNode* left_subtree = build_tree(left_margin, mid - 1);
        TreeNode* root = new TreeNode(curr->val);
        curr = curr->next;
        TreeNode* right_subtree = build_tree(mid + 1, right_margin);
        root->left = left_subtree;
        root->right = right_subtree;
        return root;
    }

   private:
    ListNode* curr = nullptr;
};

// Divide and conquer to build BST directly.
class Solution {
   public:
    TreeNode* sortedListToBST(ListNode* head) {
        return build_tree(head, nullptr);
    }

    TreeNode* build_tree(ListNode* left_margin, ListNode* right_margin) {
        if (left_margin == right_margin) {
            return nullptr;
        }

        ListNode* mid = get_mid_node(left_margin, right_margin);
        TreeNode* root = new TreeNode(mid->val);
        root->left = build_tree(left_margin, mid);
        root->right = build_tree(mid->next, right_margin);
        return root;
    }

    ListNode* get_mid_node(ListNode* left_margin, ListNode* right_margin) {
        ListNode* slow = left_margin;
        ListNode* fast = left_margin;

        while (fast != right_margin && fast->next != right_margin) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};