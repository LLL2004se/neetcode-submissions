class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;

        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        ListNode* temp = first;
        ListNode* curr = head;

        while (temp->next != nullptr) {
            temp = temp->next;
            curr = curr->next;
        }

        swap(first->val, curr->val);

        return head;
    }
};