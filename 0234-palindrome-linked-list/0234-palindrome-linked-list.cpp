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

    bool isPalindrome(ListNode* head) {
        vector<int>s;
        while(head){
            s.push_back(head->val);
            head = head->next;
        }

        int left = 0 , right = s.size()-1;
        while(left < right && s[left] == s[right]){
            left++;
            right--;
        }

        return left >= right;

    //     string str = "";
    //     ListNode* temp = head;

    //     while(temp != NULL){
    //         str += temp->val;
    //         temp = temp->next;
    //     }
    // return check(str);
    }
};