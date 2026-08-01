class Solution {
public:
    int minimumPushes(string word) {
       int n= word.size()/8;
        int ans = (8*(n)*(n+1)) /2;
        int rem = word.size()%8;
        ans += rem * (n+1);
        return ans;
    }
};