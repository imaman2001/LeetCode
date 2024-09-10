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
    int calculateGCD(int a , int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* curr = head;
        ListNode* next = head->next;

        while(next != NULL){
            int gcdval = calculateGCD(curr->val , next->val);
            ListNode* gcdNode = new ListNode(gcdval);
            curr->next = gcdNode;
            gcdNode->next = next;

            curr = next;
            next = next->next;
        }
        return head;
    }
};