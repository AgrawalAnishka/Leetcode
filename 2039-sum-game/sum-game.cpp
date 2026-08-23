class Solution {
public:
    // int solve(int sum , string & nums){
    //     for(int  i=0 ; i < nums.size() ; i ++){
    //         if(nums[i]!='?') continue ;

    //             int ans =0 ;
    //             if(i >= nums.size()/2){
    //                 for(int m =0 ;m<=9;m++){
    //                     nums[i] = char(m);
    //                     // sum-=m ;
    //                     ans = max(ans , solve(sum-m) )
    //                 }

    //             }else{
    //                  for(int m =0 ;m<=9;m++){
    //                     sum+=m ;
    //                 }
    //             }

    //     }
    // }
    bool sumGame(string nums) {
        // int n = num.size()  ;
        //  int mid = n/2 ;

        //  for(int i =0 ;i < n ; i++){
        //     if(n[i]=='?') continue;
        //     if(i>=mid){
        //         sum-=num[i]-'0';
        //     }else{
        //         sum+=num[i]-'0';
        //     }
        //  }

        //  return solve(sum , num);
        int n = nums.size();
        int mid = n / 2;
        int ql = 0;
        int qr = 0;
        int leftSum = 0;
        int rightSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == '?') {
                if (i >= mid) {
                    qr++;
                } else {
                    ql++;
                }
            } else if (i >= mid) {
                rightSum += nums[i] - '0';
            } else {
                leftSum += nums[i] - '0';
            }
        }
        int qctr = ql + qr;
        if(qctr==0)return leftSum!=rightSum ;
        if ((qctr % 2 != 0)) return true;

        if (ql == qr) {
            return leftSum != rightSum;
        }
        int diff=leftSum-rightSum;
        int qdiff=ql-qr;
        return diff+(9*qdiff)/2!=0;
    }
};