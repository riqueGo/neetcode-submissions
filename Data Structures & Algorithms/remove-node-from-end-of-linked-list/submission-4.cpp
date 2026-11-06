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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 0; i < n; i++) fast = fast->next;
        int count = n;

        while(fast != nullptr) {
            fast = fast->next;
            count++;
            if(fast == nullptr) break;
            slow = slow->next;
        }

        if(head == slow && count == n) {
            return head->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};
