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
private:
    struct compare{
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        } 
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        if(lists.size() == 0) return nullptr;
        for(int i=0; i<lists.size(); i++) {
            if(lists[i]) pq.push(lists[i]);
        }
        ListNode* result = new ListNode(0);
        ListNode* head = result;

        while(!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            if(node->next) {
                ListNode* next = node->next;
                pq.push(next);
            }
            node->next = nullptr;
            result->next = node;
            result = result->next;
        }
        return head->next;
    }
};
