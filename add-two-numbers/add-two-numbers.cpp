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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode;
        ListNode* curr;
        int sum = 0;
        
        head->val = (l1->val + l2->val)%10;
        int carry = (l1->val + l2->val)/10;
        
        l1 = l1->next;
        l2 = l2->next;
        
        curr = head;
        while(l1 and l2){
            curr->next = new ListNode;
            curr = curr->next;
            
            sum   = (l1->val + l2->val + 1*carry)%10;
            carry = (l1->val + l2->val + 1*carry)/10;
            curr->val = sum;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1){
            if(carry){
                curr->next = new ListNode;
                curr = curr->next;
                
                sum   = (l1->val + 1)%10;
                carry = (l1->val + 1)/10;
                curr->val = sum;
            }else{
                curr->next = l1;
                break;
            }
            l1 = l1->next;
        }
        
        while(l2){
            if(carry){
                curr->next = new ListNode;
                curr = curr->next;
                
                sum   = (l2->val + 1)%10;
                carry = (l2->val + 1)/10;
                curr->val = sum;
            }else{
                curr->next = l2;
                break;
            }
            l2 = l2->next;
        }
        
        if(carry){
            curr->next = new ListNode(1);
        }
        
        return head;
    }
};