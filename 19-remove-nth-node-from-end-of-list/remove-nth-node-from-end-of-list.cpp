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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) return NULL;
       
        int ctr =1 ;
        ListNode* curr = head;
        while(curr){
            ctr++;
            curr= curr->next ;

             
        }

        int nth = ctr-n ; 
        if(nth==1) return head->next ;
        // cout<<nth<<endl;
        ListNode* temp = head;
        ListNode* prev = NULL;
        int c =1 ;
        while(c < nth){
            prev= temp;
            temp  = temp->next ;
            c++;

        }
        cout<<temp->val<<endl;
        if(temp->next==NULL) prev->next=NULL;
        else prev->next =  temp->next;

        return head;


    }
};