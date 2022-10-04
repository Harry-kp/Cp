class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        set<char> s1;
        int n = s.size();
        // cout<<n<<'\n';
        int ans = 0,cnt;
        for(int i = 0;i<n;i++){
            s1.clear();
            cnt = 0;
            for(int j = i;j<n;j++){
                if(s1.find(s[j]) == s1.end()){
                    cnt++;
                   s1.insert(s[j]);
                }else
                    break;
            }
            
            ans = max(ans,cnt);
        }
        return ans;
    }
};