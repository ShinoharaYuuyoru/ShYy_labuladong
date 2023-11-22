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
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (1) {
            if (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;

                if (slow == fast) {
                    ListNode* start = head;
                    while (1) {
                        if (start == slow) {
                            return start;
                        }

                        start = start->next;
                        slow = slow->next;
                    }
                }
            } else {
                break;
            }
        }

        return nullptr;
    }
};
