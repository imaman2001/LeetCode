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
// Optimal approach using Hare / Tortoise Algorithms
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        if(head == NULL || head->next == NULL){
            return false;
        }

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
                return true;
            }
        }
        return false;
    }
    

// Brute Force
    // bool hasCycle(ListNode *head){
    //     unordered_map<ListNode*, int>mpp;
    //     ListNode* temp = head;

    //     while(temp != nullptr){
    //         // if node match with mid
    //         if(mpp.find(temp) != mpp.end()){
    //             return true;
    //         }
    //         //visited
    //         mpp[temp] = 1;

    //         //traverse
    //         temp = temp->next;
    //     }
    //     return false;
    // }
};