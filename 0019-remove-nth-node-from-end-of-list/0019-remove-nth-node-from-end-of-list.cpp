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
        ListNode tmp(0, head); // node: [0, head]
        ListNode* after_target = &tmp;
        ListNode* before_target = &tmp;
        for (int i = 0; i <= n; i++) {
            if (after_target == nullptr) return head; // n is larger than list length
            after_target = after_target->next;
        }

        while (after_target != nullptr) {
            after_target = after_target->next;
            before_target = before_target->next;
        }
        ListNode* toBeDeleted = before_target->next;
        before_target->next = before_target->next->next;
        delete toBeDeleted;

        return tmp.next;
    }
};