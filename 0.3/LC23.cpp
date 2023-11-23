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
// Template
class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0, nullptr);
        ListNode* p_new = dummy;

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (auto head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            p_new->next = node;
            p_new = p_new->next;
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        return dummy->next;
    }

   private:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
};

// Lambda
class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0, nullptr);
        ListNode* p_new = dummy;

        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)> > pq(
            [](ListNode* a, ListNode* b) { return a->val > b->val; });
        for (auto head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            p_new->next = node;
            p_new = p_new->next;
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};