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
// Brute Force
    // ListNode* deleteMiddle(ListNode* head) {
    //     ListNode* temp = head;
    //     int n = 0;

    //     while(temp != NULL){
    //         n++;
    //         temp = temp->next;
    //     }

    //     int mid = n/2;
    //     temp = head;

    //     while(temp != NULL){
    //         mid--;

    //         if(mid == 0){
    //             ListNode* middle = temp->next;
    //             temp->next = temp->next->next;
    //             delete(middle->next);
    //             break;
    //         }

    //         temp = temp->next;
    //     }
    //     return head;
    // }

// Optimal
    ListNode* deleteMiddle(ListNode* head){
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = slow->next->next;
        delete mid;

        return head;
    }
};