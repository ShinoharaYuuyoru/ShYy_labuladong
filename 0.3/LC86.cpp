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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less_dummy = new ListNode(-1, nullptr);
        ListNode* eq_gt_dummy = new ListNode(-1, nullptr);
        ListNode* p1 = less_dummy;
        ListNode* p2 = eq_gt_dummy;

        ListNode* p = head;
        while (p != nullptr) {
            ListNode* temp = p->next;
            p->next = nullptr;
            if (p->val < x) {
                p1->next = p;
                p1 = p1->next;
            } else {
                p2->next = p;
                p2 = p2->next;
            }
            p = temp;
        }
        p1->next = eq_gt_dummy->next;
        return less_dummy->next;
    }
};