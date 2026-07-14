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
    // ListNode* oddEvenList(ListNode* head) {
    //     ListNode* oddHead = new ListNode(-1);
    //     ListNode* evenHead = new ListNode(-1);

    //     ListNode* oddTail = oddHead;
    //     ListNode* evenTail = evenTail;

    //     ListNode* curr = head , *temp = nullptr;

    //     while(curr){
    //         temp = curr;        // temp --> null  to curr
    //         curr = curr->next;   // move to the next node
    //         temp->next = nullptr;   // temp->next = null

    //         if(temp->val % 2 == 1){ // odd
    //             oddTail->next = temp;
    //             oddTail = temp;
    //         } else {
    //             evenTail->next = temp;
    //             evenTail = temp;
    //         }
    //     }
    //     oddTail->next = evenHead->next;

    //     return oddHead->next;
    // }

    ListNode* oddEvenList(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even != NULL && even->next != NULL){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = odd->next;
        }

        odd->next = evenHead;

        return head;
    }
};