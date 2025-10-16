/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;

        ListNode *P1 = headA;
        ListNode *P2 = headB;

        while(P1 != P2){
            P1 = P1 == NULL ? headB : P1->next;
            P2 = P2 == NULL ? headA : P2->next;
        }
        return P1;
    }
};