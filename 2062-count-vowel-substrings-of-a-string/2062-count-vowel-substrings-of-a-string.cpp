class Solution {
public:
    int countVowelSubstrings(string w) {
        int total =0 ;
        for(int i  =0 ;i <w.size();i++){
            
            set<char>s ;
             for(int j = i ; j<w.size() ; j++){
                if(w[j]=='a' ||w[j]=='e' ||w[j]=='o' || w[j]=='u' || w[j]=='i') {
                    s.insert(w[j]);
                    if(s.size()==5) total++;
                }else break;
                
                
             }
        }
        return total;
    }
};