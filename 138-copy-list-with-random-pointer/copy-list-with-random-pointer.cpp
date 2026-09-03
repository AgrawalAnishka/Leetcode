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
        if (!head)
            return NULL;
        unordered_map<Node*, Node*> mp;
        Node* nakliHead = new Node(head->val);
        Node* temp = nakliHead;
        Node* curr = head->next;
        // int ind =0 ;
        mp[head] = nakliHead;
        while (curr) {


            temp->next = new Node(curr->val);
            mp[curr] = temp->next;
            temp = temp->next;
            curr = curr->next;
        }
        curr = head;
        temp = nakliHead;
        while (curr) {
            if(curr->random ){
                cout<<curr->random->val<<endl;
            temp->random = mp[curr->random];
            }
            curr = curr->next;
            temp = temp->next;
        }
        return nakliHead;
    }
};