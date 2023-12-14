/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* left = dummy;
        ListNode* right = head;
        while (right != nullptr) {
            if (right->val == val) {
                left->next = right->next;
                break;
            }
            left = left->next;
            right = right->next;
        }
        return dummy->next;
    }
};