class Solution {
public:
    ListNode* doubleIt(ListNode* head) {

        ListNode* temp;
        if (head->val > 4) {
            ListNode* node = new ListNode(1);
            node->next = head;
            head = node;
            temp = head->next;
        }
        else {
            temp = head;
        }
        while (temp != NULL) {

            int carry = 0;
            if (temp->next != NULL && temp->next->val > 4) {
                carry = 1;
            }
            int newval = (temp->val * 2 + carry) % 10;
            temp->val = newval;
            temp = temp->next;
        }

        return head;
    }
};