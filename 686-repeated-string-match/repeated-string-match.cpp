class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int ctr =1 ;
        string dup =a;
        while(dup.size()< b.size()){
            dup+=a;
            ctr++;

        }
        if(dup.find(b)!=string::npos) return ctr;
        ctr++;
        dup+=a;
        if(dup.find(b)!=string::npos) return ctr ;
        return -1; 
    }
};