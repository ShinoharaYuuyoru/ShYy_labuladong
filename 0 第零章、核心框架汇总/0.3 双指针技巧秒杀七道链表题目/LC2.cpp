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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1, nullptr);
        ListNode* p = dummy;

        ListNode* p1 = l1;
        ListNode* p2 = l2;
        bool carry = false;
        while (1) {
            if (p1 == nullptr && p2 == nullptr) {
                if (carry == true) {
                    p->next = new ListNode(1, nullptr);
                    p = p->next;
                }
                break;
            } else {
                if (p1 == nullptr && p2 != nullptr) {
                    while (1) {
                        if (p2 == nullptr) {
                            if (carry == true) {
                                carry = false;
                                p->next = new ListNode(1, nullptr);
                                p = p->next;
                            }
                            break;
                        } else {
                            int sum = (carry == true) ? (p2->val + 1) : (p2->val);
                            carry = (sum > 9) ? (true) : (false);
                            int digit = (sum > 9) ? (sum - 10) : (sum);
                            p->next = new ListNode(digit, nullptr);
                            p = p->next;
                            p2 = p2->next;
                        }
                    }
                    break;
                } else if (p1 != nullptr && p2 == nullptr) {
                    while (1) {
                        if (p1 == nullptr) {
                            if (carry == true) {
                                carry = false;
                                p->next = new ListNode(1, nullptr);
                                p = p->next;
                            }
                            break;
                        } else {
                            int sum = (carry == true) ? (p1->val + 1) : (p1->val);
                            carry = (sum > 9) ? (true) : (false);
                            int digit = (sum > 9) ? (sum - 10) : (sum);
                            p->next = new ListNode(digit, nullptr);
                            p = p->next;
                            p1 = p1->next;
                        }
                    }
                    break;
                } else {
                    int sum = (carry == true) ? (p1->val + p2->val + 1) : (p1->val + p2->val);
                    carry = (sum > 9) ? (true) : (false);
                    int digit = (sum > 9) ? (sum - 10) : (sum);
                    p->next = new ListNode(digit, nullptr);
                    p = p->next;
                    p1 = p1->next;
                    p2 = p2->next;
                }
            }
        }

        return dummy->next;
    }
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode* dummy = new ListNode(-1, nullptr);
        ListNode* p = dummy;

        int carry = 0;
        while (p1 != nullptr || p2 != nullptr || carry > 0) {
            int sum = carry;
            if (p1 != nullptr) {
                sum += p1->val;
                p1 = p1->next;
            }
            if (p2 != nullptr) {
                sum += p2->val;
                p2 = p2->next;
            }

            carry = sum / 10;
            int digit = sum % 10;
            ListNode* val = new ListNode(digit, nullptr);
            p->next = val;
            p = p->next;
        }

        return dummy->next;
    }
};