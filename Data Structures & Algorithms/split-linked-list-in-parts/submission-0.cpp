class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;

        while (curr) {
            n++;
            curr = curr->next;
        }

        int size = n / k;
        int extra = n % k;

        vector<ListNode*> ans(k, nullptr);
        curr = head;

        for (int i = 0; i < k; i++) {
            ans[i] = curr;

            int partSize = size + (extra > 0 ? 1 : 0);
            extra--;

            for (int j = 0; j < partSize - 1; j++) {
                if (curr) curr = curr->next;
            }

            if (curr) {
                ListNode* nextPart = curr->next;
                curr->next = nullptr;
                curr = nextPart;
            }
        }

        return ans;
    }
};