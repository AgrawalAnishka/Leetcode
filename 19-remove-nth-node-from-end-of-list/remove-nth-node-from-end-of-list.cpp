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
        // if(n==1 && head->next ==NULL){
          
        //     return head ; 
        // }
        ListNode* ptr = head;
        int total = 0;
        while (ptr) {
            ptr = ptr->next;
            total++;
        }
        int d = total - n;
        if(d==0) return head!=NULL ? head->next :NULL;
        int i = 0;
        ListNode* prev = head;
        ListNode* curr = head;
        while (i < d && curr != NULL) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        if (curr->next) {
            prev->next = curr->next;
        } else {
            prev->next = NULL;
        }
        return head;
    }
};