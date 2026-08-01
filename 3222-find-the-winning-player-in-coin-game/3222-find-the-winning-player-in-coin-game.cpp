class Solution {
public:
    string winningPlayer(int x, int y) {
        int temp = y/4;
          if (temp > x) temp = x;

        if (temp % 2 == 0) {
            return "Bob";
        } else {
            return "Alice";
        }
        // if(temp<x && temp%2==0){
        //     return "Bob";
        // }else{
        //     return "Alice";
        // }
    //    if(x>=1 && y>=7){
    //     return "Alice";
    //    }else{
    //     return "Bob";
    //    }
    }
};