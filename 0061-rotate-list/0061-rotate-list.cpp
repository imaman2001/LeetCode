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
        if(!head) return head;

        int len = 1;
        ListNode* dummy = head;

        while(dummy->next != NULL){
            dummy = dummy->next;
            len++;                //3
        }

        int pos = k % len;  // 1
        if(pos == 0) return head;   // no need to rotate

        ListNode* curr = head;
        for(int i=0; i < len - pos - 1; i++){
            curr = curr->next;
        }

        ListNode* newHead = curr->next;
        curr->next = nullptr;
        dummy->next = head;

        return newHead;
    }
};