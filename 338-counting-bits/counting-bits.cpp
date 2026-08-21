class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res ; 
        for(int mask = 0 ; mask <= n ; mask++){
            int bits =0 ;
            for(int  i =0 ;i < 31; i ++){
                if(mask & (1<<i)){
                    bits++;
                }
                
            }
            res.push_back(bits);

        }
        return res;
    }
};