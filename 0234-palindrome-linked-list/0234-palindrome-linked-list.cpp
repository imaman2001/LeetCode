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
    bool check(string s){
        int n = s.size();
        for(int i=0; i<n/2; i++){
            if(s[i] != s[n-i-1]){
                return false;
            }
        }
        return true;
    }

    ListNode* reverseLL(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* prev = NULL;

        ListNode* newNode = reverseLL(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = prev;

        return newNode;
    }

    // bool isPalindrome(ListNode* head) {
    //     // vector<int>s;
    //     // while(head){
    //     //     s.push_back(head->val);
    //     //     head = head->next;
    //     // }
    //     // int left = 0 , right = s.size()-1;
    //     // while(left < right && s[left] == s[right]){
    //     //     left++;
    //     //     right--;
    //     // }
    //     // return left >= right;


    //     // stack<int> st;
    //     // ListNode* temp = head;
    //     // while(temp != NULL){
    //     //     st.push(temp->val);
    //     //     temp = temp->next;
    //     // }
    //     // temp = head;
    //     // while(temp != NULL){
    //     //     if(st.top() != temp->val){
    //     //         return false;
    //     //     }
    //     //     st.pop();
    //     //     temp = temp->next;
    //     // }
    //     // return true;
    // }

    bool isPalindrome(ListNode* head){
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseLL(slow->next);
        ListNode* firstHead = head;
        ListNode* secondHead = newHead;

        while(secondHead != NULL){
            // compare first and second half
            if(firstHead->val != secondHead->val){
                return false;
            }
            firstHead = firstHead->next;
            secondHead = secondHead->next;
        }
        reverseLL(newHead);
        return true;
    }
};