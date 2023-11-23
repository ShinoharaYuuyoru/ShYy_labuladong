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
class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0, nullptr);
        ListNode* p_new = dummy;

        ListNode* p1 = list1;
        ListNode* p2 = list2;
        while (1) {
            if (p1 == nullptr) {
                p_new->next = p2;
                break;
            }
            if (p2 == nullptr) {
                p_new->next = p1;
                break;
            }

            if (p1->val < p2->val) {
                p_new->next = p1;
                p1 = p1->next;
                p_new = p_new->next;
            } else {
                p_new->next = p2;
                p2 = p2->next;
                p_new = p_new->next;
            }
        }

        return dummy->next;
    }
};