class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);  // Create a dummy head node
        ListNode* current = dummyHead;  // Pointer to traverse the result list
        int carry = 0;  // Carry value for addition

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = 0;  // Sum of digits in current position

            // Add values from l1 and l2 (if they exist)
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Add the carry from the previous addition
            sum += carry;

            // Calculate the new digit and carry
            carry = sum / 10;
            int digit = sum % 10;

            // Create a new node for the digit and append it to the result list
            current->next = new ListNode(digit);
            current = current->next;
        }

        return dummyHead->next;  // Return the actual head of the result list
    }
};