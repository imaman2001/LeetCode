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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp = new ListNode();
        int max = -1;
        for(int num : nums){
            if(num > max){
                max = num;
            } else {
                max = max;
            }
        }

        vector<bool> freq(max + 1 , false);
        for(int num : nums){
            freq[num] = true;
        }

        ListNode* curr = temp;

        while(head != NULL){
            if(head->val >= freq.size() || !freq[head->val]){
                curr->next = head;
                curr = curr->next;
            }
            head= head->next;
        }
        curr->next = NULL;
        return temp->next;
    }
};