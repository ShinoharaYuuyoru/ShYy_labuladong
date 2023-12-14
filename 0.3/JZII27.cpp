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

// Create a reverse list.
class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        ListNode* reverse_list = new ListNode(-1);
        ListNode* head_r = reverse_list->next;

        ListNode* p = head;
        while (p != nullptr) {
            ListNode* curr = new ListNode(p->val);
            reverse_list->next = curr;
            curr->next = head_r;
            head_r = curr;

            p = p->next;
        }

        p = head;
        ListNode* p2 = reverse_list->next;
        while (p != nullptr) {
            if (p->val != p2->val) {
                return false;
            }

            p = p->next;
            p2 = p2->next;
        }
        return true;
    }
};

// Reverse the half list.
class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // If num(list) == odd, which fast->next == nullptr, slow is at the middle.
        // If num(list) == even, which fast == nullptr, slow is at the next of middle.
        if (fast != nullptr) {
            slow = slow->next;
        }

        ListNode* scan_left = head;
        ListNode* scan_right = reverse_list(slow);
        while (scan_right != nullptr) {
            if (scan_left->val != scan_right->val) {
                return false;
            }

            scan_left = scan_left->next;
            scan_right = scan_right->next;
        }
        return true;
    }

   private:
    ListNode* reverse_list(ListNode* head) {
        ListNode *next = nullptr, *curr = head;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = next;
            next = curr;
            curr = temp;
        }
        return next;
    }
};

// List traverse with pre-order and post-order.
class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        left = head;
        return traverse(head);
    }

   private:
    ListNode* left;

    bool traverse(ListNode* head) {
        if (head == nullptr) {
            return true;
        }

        bool res = traverse(head->next);

        res = res && (left->val == head->val);
        if (res == true) {
            left = left->next;
        }
        return res;
    }
};