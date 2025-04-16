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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;
        while(head != NULL && head->val == val){
            head = head->next;
        }

        ListNode* prePtr = NULL;
        ListNode* ptr = head;
        
        while(ptr != NULL){
            if(ptr->val == val){
                prePtr->next = ptr->next;
                ptr = ptr->next;
            } else {
                prePtr = ptr;
                ptr = ptr->next;
            }
        }
        return head;
    }
};