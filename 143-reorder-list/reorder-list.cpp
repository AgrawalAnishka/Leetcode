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
    ListNode* solve(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* tail = head;
        ListNode* chotaTail = head;

        while(tail->next){
            chotaTail = tail ; 
            tail = tail->next ; 
        }
        // cout<<tail->val <<chotaTail->val<<endl; 
        if(head==chotaTail) return head;
        chotaTail->next  = NULL;
        if(head->next==NULL) return head;
        ListNode* nexthead = head->next ;
        head->next = tail ; 
        tail->next = solve(nexthead);

        return head ; 
        
    }
    void reorderList(ListNode* head) {
        if(!head ||!head->next){
            return ; 
        }
        solve(head);
    }
};