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
// Iterative
class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* left_list_tail = dummy;
        for (unsigned int i = 0; i < left - 1; i++) {
            left_list_tail = left_list_tail->next;
        }
        ListNode* mid_head = left_list_tail->next;
        ListNode* right_list_head = head;
        for (unsigned int i = 0; i < right; i++) {
            right_list_head = right_list_head->next;
        }

        ListNode* pre = right_list_head;
        ListNode* curr = mid_head;
        while (curr != right_list_head) {
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        left_list_tail->next = pre;

        return dummy->next;
    }
};

// Recursive
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == 1){
            return reverse_n(head, right);
        }

        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
private:
    ListNode* remain_head = nullptr;
    ListNode* reverse_n(ListNode* head, int n){
        if(n == 1){
            remain_head = head->next;
            return head;
        }

        ListNode* new_head = reverse_n(head->next, n - 1);
        head->next->next = head;
        head->next = remain_head;
        return new_head;
    }
};
