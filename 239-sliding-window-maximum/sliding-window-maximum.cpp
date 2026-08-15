class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q ; 
        vector<int> res;
        for(int i  =0 ;i < k ; i++){
            while(!q.empty() && q.back() < nums[i] ){
                q.pop_back();
            }
            q.push_back(nums[i]);
        }
        res.push_back(q.front());
        int l = 0 ; 
        int r = k ; 
        while(r< nums.size()){
            if(q.front()==nums[l]){
                q.pop_front();
            }
             while(!q.empty() && q.back() < nums[r] ){
                q.pop_back();
            }
            q.push_back(nums[r]);
            res.push_back(q.front());
            l++;
            r++;

        }
        return res;
    }
};