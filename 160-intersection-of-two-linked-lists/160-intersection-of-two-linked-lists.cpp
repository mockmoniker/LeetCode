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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> map;
        ListNode* curr;
        
        curr = headA;
        while(curr){
            map[curr]++;
            curr = curr->next;
        }
        
        curr = headB;
        while(curr){
            if(map[curr]){
                return curr;
            }
            curr = curr->next;
        }
        
        return NULL;
    }
};