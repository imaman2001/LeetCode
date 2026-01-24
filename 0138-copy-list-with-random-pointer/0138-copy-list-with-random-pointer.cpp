/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Node* copyRandomList(Node* head) {
        
    //     Node* temp = head;
    //     unordered_map<Node* , Node*>mpp;
    //     while(temp != NULL){
    //         Node* newNode = new Node(temp->val);
    //         mpp[temp] = newNode;
    //         temp = temp->next;
    //     }
    //     temp = head;
    //     while(temp != nullptr){
    //         Node* copyNode = mpp[temp];
    //         copyNode->next = mpp[temp->next];
    //         copyNode->random = mpp[temp->random];
    //         temp = temp->next;
    //     }
    //     return mpp[head];
    // }

/// optimal approach
    Node* copyRandomList(Node* head){
        Node* temp = head;
        //create copy nodes of every temp node's in between ll
        while(temp != NULL){
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
        temp = head;
        // initilize the copy's random from temp->random
        while(temp != NULL){
            Node* copyNode = temp->next;  
            if(temp->random){
                copyNode->random = temp->random->next; // initilize the whole node to copyNode
            } else{
                copyNode->random = NULL;
            } 
            temp = temp->next->next;
        }
        temp = head;
        //initilize the next into copyNode and seprate the copy linkedlist
        Node* dummy = new Node(-1);
        Node* res = dummy;
        while(temp != NULL){
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        } 
        return dummy->next;
    }
};