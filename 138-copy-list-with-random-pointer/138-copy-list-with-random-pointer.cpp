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
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> equivNewNode;
        
        // case: empty linked list
        if(!head){
            return NULL;
        }
        
        // case: only one element in linked list
        if(!head->next){
            Node* onlyHead = new Node(head->val);
            if(head->random == head){
                onlyHead->random = onlyHead;
            }
            return onlyHead;
        }
        
        Node* curr = head->next;
        Node* newHead = new Node(head->val);
        Node* prev = newHead;
        
        equivNewNode[head] = newHead;
        
        while(curr){
            Node* newNode = new Node(curr->val);
            prev->next = newNode;
            equivNewNode[curr] = newNode;
            prev = newNode;
            
            curr = curr->next;
        }
        
        Node* newCurr = newHead;
        curr = head;
        while(newCurr){
            newCurr->random = equivNewNode[curr->random];
            
            newCurr = newCurr->next;
            curr = curr->next;
        }
        
        return newHead;
    }
};