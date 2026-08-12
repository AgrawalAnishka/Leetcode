class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size());
        int len = 0;
        int m = needle.size();
        int i = 1;
        while (i < m) {
            if (needle[len] == needle[i]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    len = lps[len - 1];
                }
            }
        }

        i = 0;
        int j = 0;
        int n = haystack.size();
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            
            if (j == m) {
                return i-j;
                j=lps[j-1];
            }
            else if (i<n &&  haystack[i]!=needle[j]){
                if(j != 0) {
                    j = lps[j - 1];
                }
                else{
                    i++;
                }
            }
                
               
            
        }
        return -1;
    }
};