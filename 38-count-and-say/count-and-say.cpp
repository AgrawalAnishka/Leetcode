class Solution {
public:
    string countAndSay(int n) {
        queue<int> q ;

        q.push(1);

        while(n>1 ){
            int ans  =0 ;
            int temp = q.front();
            int size = q.size();
            n--;
                while(size--){
                    int top = q.front();
                    q.pop();
                    if(temp==top){
                        
                        ans++;
                    }else{
                        
                        q.push(ans);
                        q.push(temp);
                        temp = top ; 
                        ans=1;
                    }
                }
                // if(ans >0){
                    q.push(ans);
                    q.push(temp);
                    
                // }
            
        }
        string ans = "";

        while(!q.empty()){
            ans+= to_string(q.front())  ;
            q.pop();
        }

        return ans ;


    }
};