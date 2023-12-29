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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        ListNode *slow = head, *fast = head->next;
        int dup_flag = 0;
        while (1) {
            while (fast != nullptr) {
                if (slow->val == fast->val) {
                    fast = fast->next;
                    dup_flag = 1;
                } else {
                    break;
                }
            }
            if (dup_flag == 0) {
                p->next = slow;
                p = p->next;
                p->next = nullptr;
            }

            slow = fast;
            if (fast == nullptr) {
                break;
            } else {
                fast = fast->next;
                dup_flag = 0;
            }
        }
        return dummy->next;
    }
};

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode *p = dummy, *q = head;
        while (q != nullptr) {
            if (q->next != nullptr && q->val == q->next->val) {
                while (q->next != nullptr && q->val == q->next->val) {
                    q = q->next;
                }
                q = q->next;
                if (q == nullptr) {
                    p->next = nullptr;
                }
            } else {
                p->next = q;
                p = p->next;
                q = q->next;
            }
        }
        return dummy->next;
    }
};

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        } else {
            if (head->val != head->next->val) {
                head->next = deleteDuplicates(head->next);
                return head;
            } else {
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                head = head->next;
                return deleteDuplicates(head);
            }
        }
    }
};