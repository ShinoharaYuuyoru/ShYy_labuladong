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
    ListNode* trainningPlan(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0, nullptr);
        ListNode* p = dummy;

        while (1) {
            if (l1 == nullptr) {
                p->next = l2;
                break;
            }
            if (l2 == nullptr) {
                p->next = l1;
                break;
            }

            if (l1->val < l2->val) {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }

        return dummy->next;
    }
};