class Solution {
public:
    char findTheDifference(string s, string t) {
        int x  = 0;
        for(auto ch :  s ){
            x^=(ch-'a');
        }

        for(auto ch: t){
            x^=(ch-'a');
        }

        return x+'a';
    }
};