class Solution {
public:
void solve(int i ,  int k , vector<int> & nums){
    int n  = nums.size();
    if(i>=n) return  ; 
    int temp = nums[i];

    solve(i+1 ,  k , nums);

    nums[(i+k) % n] = temp;


}
    void rotate(vector<int>& nums, int k) {
         solve( 0 , k,  nums );
    }
};