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
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* newNode = NULL;
    //     while(head != NULL){
    //         ListNode* temp = head->next;
    //         head->next = newNode;
    //         newNode = head;
    //         head = temp;
    //     }
    //     return newNode;
    // }

    // ListNode* reverseList(ListNode* head){
    //     ListNode* prev = nullptr;
    //     ListNode* temp = head;
    //     while(temp != nullptr){
    //         ListNode* front = temp->next;
    //         temp->next = prev;
    //         prev = temp;
    //         temp = front;
    //     }
    //     return prev;
    // }

// with recursion 
    ListNode* reverseList(ListNode* head){
        //Base Case
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* newNode = reverseList(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newNode;
    }
};