
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        // Step 1: Create copies and insert them
        Node* curr = head;

        while (curr != nullptr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Step 2: Assign random pointers
        curr = head;

        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        // Step 3: Separate original and copied lists
        Node* dummy = new Node(0);
        Node* copyTail = dummy;

        curr = head;

        while (curr != nullptr) {
            Node* copy = curr->next;

            curr->next = copy->next;
            copyTail->next = copy;

            copyTail = copy;
            curr = curr->next;
        }

        Node* result = dummy->next;
        delete dummy;

        return result;
    }
};
