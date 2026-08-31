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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL | head->next==NULL || head->next->next==NULL){
            return {-1, -1}; 
        }
        int first = -1 ;
        int latest= -1 ;
        int small = INT_MAX;
        
        ListNode* prev = head;
        ListNode* curr = head->next ;
         ListNode* nxt = head->next->next ;
        int i =2;

         while(nxt){
            if((prev->val > curr->val &&curr->val <  nxt->val) || (prev->val <  curr->val && curr->val > nxt->val)){
                if(latest!=-1){
                    small =min(small, i-latest  );
                    latest = i ;
                }
                if(first==-1) {
                    first = i ;
                    latest = i; 
                } ;
                
            }
            prev = curr;
            curr = nxt ;
             nxt = nxt->next ; 

            i++;
         }
         if(latest==-1 || first==-1 ||small==INT_MAX)  {
            return  {-1, -1};
         }
        small = min(small,  latest-first);
         return {small, latest-first};
        
    }
};