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
    void incrementAndIterate(ListNode*& node, int &carry, int val) {
        carry = val / 10;
        val = val % 10;

        ListNode* newNode = new ListNode(val);
        node->next = newNode;
        node = node->next;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* curr = new ListNode(0);
        ListNode* head = curr;

        while(l1 != nullptr && l2 != nullptr) {
            int val = l1->val + l2->val + carry;
            incrementAndIterate(curr, carry, val);
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != nullptr) {
            int val = l1->val + carry;
            incrementAndIterate(curr, carry, val);
            l1 = l1->next;
        }

        while(l2 != nullptr) {
            int val = l2->val + carry;
            incrementAndIterate(curr, carry, val);
            l2 = l2->next;
        }

        if(carry) {
            curr->next = new ListNode(1);
        }


        return head->next;
    }
};
