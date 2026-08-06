class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) {
            return nullptr;
        } 
        if (left == right) {
            return head;
        }

        ListNode* t = head;
        ListNode* before = nullptr;
        int pos = 1;

        // Step 1: Traverse to 'left' position and track 'before'
        while (t != nullptr && pos < left) {
            before = t;
            t = t->next;
            pos++;
        }

        // Step 2: Reverse the sublist from 'left' to 'right'
        ListNode* curr = t;
        ListNode* prev = nullptr;
        int times = right - left + 1;

        while (times--) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode; // Fix: Advance curr
        }

        // Step 3: Reconnect the reversed sublist back to the main list
        t->next = curr;

        if (before) {
            before->next = prev;
        } else {
            head = prev; // Fix: Update head if reversing started at index 1
        }

        return head;
    }
};