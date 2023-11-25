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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)> > pq(
            [](ListNode* a, ListNode* b) {
                return a->val > b->val;
            });

        for (auto list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        ListNode* dummy = new ListNode(0, nullptr);
        ListNode* p = dummy;
        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();
            if (curr->next != nullptr) {
                pq.push(curr->next);
            }

            p->next = curr;
            p = p->next;
        }

        return dummy->next;
    }
};