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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;
        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL){
            ListNode* temp = curr->next->next;

            tail->next = curr->next;
            curr->next->next = curr;
            curr->next =  temp;

            tail = curr;
            curr = temp;
        }
        return dummy.next;
    }
};