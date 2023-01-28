class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> set1;
        
        int ans = 0,l = 0,r = 0,n = s.size();
        
        while(r<n){
            
            if(set1.find(s[r]) != set1.end()){
                while(set1.find(s[r]) != set1.end()){
                    set1.erase(s[l]);
                    l++;
                }
            }
            ans = max(ans,r-l+1);
            set1.insert(s[r]);
                r++;
        }
        return ans;
        
        
    }
};