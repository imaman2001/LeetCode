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
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     ListNode* temp = new ListNode(0);
    //     temp->next = head;
    //     ListNode* first = temp;
    //     ListNode* second = temp;

    //     for(int i=0; i<=n; i++){
    //         first = first->next;
    //     }

    //     while(first != NULL){
    //         first = first->next;
    //         second = second->next;
    //     }

    //     ListNode* non = second->next;
    //     second->next = second->next->next;
    //     delete non;

    //     return temp->next;
    // }

// Brute Force approach
    // ListNode* removeNthFromEnd(ListNode* head, int n){

    //     ListNode* temp = head;
    //     int count = 0;
    //     while(temp != nullptr){
    //         count++;
    //         temp = temp->next;
    //     }
    //     if(count == n){ // delete head
    //         ListNode* newNode = head->next;
    //         delete head;
    //         return newNode;
    //     }
    //     temp = head;
    //     int res = count - n;

    //     while(temp != nullptr){
    //         res--;
    //         if(res == 0){
    //             break;
    //         }
    //         temp = temp->next;
    //     }

    //     ListNode* deleteNode = temp->next;
    //     temp->next = temp->next->next;
    //     delete deleteNode;
    //     return head;
    // }

// optimal solution
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* slow = temp;
        ListNode* fast = temp;

        for(int i=0; i<=n; i++){
            fast = fast->next;
        }

        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return temp->next;
    }
};