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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Step 1: Find the length (n) and the last node
        ListNode* last = head;
        int n = 1;
        while (last->next != nullptr) {
            n++;
            last = last->next;
        }

        // Step 2: Handle cases where k >= n or k == 0
        k = k % n;
        if (k == 0) {
            return head;
        }

        // Step 3: Connect last node to head to form a circle
        last->next = head;

        // Step 4: Traverse to the (n - k)-th node
        ListNode* t = head;
        for (int count = 1; count < n - k; count++) {
            t = t->next;
        }

        // Step 5: Set the new head and break the circular link
        ListNode* res = t->next;
        t->next = nullptr;

        return res;
    }
};