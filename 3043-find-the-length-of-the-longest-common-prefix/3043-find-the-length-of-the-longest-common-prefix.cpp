class Node {
public:
    vector<Node*> d;
    bool next;

    Node() {

        d.resize(10, NULL);
        next = false;
    }
} ;
class Trie {
public:
    Node* root;

    Trie() { root = new Node(); }

    void insert(int data) {
        string s = to_string(data);

        Node* temp = root;

        for (int i = 0; i < s.size(); i++) {
            int digit = s[i] - '0';
            if (temp->d[digit] == NULL) {
                temp->d[digit] = new Node();
            }
            temp = temp->d[digit];
        }
    }
    int check(int data) {
        int ans = 0;
        string s = to_string(data);
        Node* curr = root;
        for (int i = 0; i < s.size(); i++) {

            if (curr->d[s[i]-'0'] ) {
                ans++;
                curr = curr->d[s[i]-'0'];
            }else{
                break;
            }
        }
        return ans;
    }

};

class Solution {

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans  =0 ;
        Trie t;
        for (int i = 0; i < arr1.size(); i++) {
            t.insert(arr1[i]);
        }

        for(int i =0 ;i<arr2.size() ; i++){
            ans = max(ans , t.check(arr2[i]));
        }
        return ans ;
    }
};