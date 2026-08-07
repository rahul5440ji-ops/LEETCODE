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
    void reverseGroup(ListNode* head, int times){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(times-- && curr){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
    }

    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode* left = head;
        ListNode* right;
        ListNode* res = nullptr;
        ListNode* prevleft = nullptr;
        int size = 2;

        while(true){
            right = left;
            for(int i = 0; i < size - 1; i++){
                if(right == nullptr) break;
                right = right->next;
            }
            if(right){
                ListNode* nextleft = right->next;
                reverseGroup(left, size);
                if(prevleft) prevleft->next = right;
                prevleft = left;
                if(res == nullptr) res = right;
                left = nextleft;
            } else {
                if(prevleft) prevleft->next = left;
                if(res == nullptr) res = left;
                break;
            }
        }
        return res;
    }
};