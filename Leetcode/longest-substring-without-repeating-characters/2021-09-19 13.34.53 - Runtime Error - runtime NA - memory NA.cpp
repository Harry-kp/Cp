class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int A[26],n = s.size();
        int ans = 0,cnt;
        for(int i = 0;i<n;i++){
            fill(A,A+26,0);
            cnt = 0;
            for(int j = i;j<n;j++){
                if(A[s[j]-'a'] == 0){
                    cnt++;
                    A[s[j]-'a']++;
                }else
                    break;
            }
            
            ans = max(ans,cnt);
        }
        return ans;
    }
};