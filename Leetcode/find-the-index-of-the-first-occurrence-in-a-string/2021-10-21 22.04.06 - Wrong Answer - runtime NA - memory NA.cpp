class Solution {
public:
    vector<int> lps(string p){
        int n = p.size();
        vector<int> pie(n);
        
        int j = 0;
        for(int i = 0;i<n;i++){
            while(p[i]!=p[j] and j>0)j = pie[i-1];
            if(p[i] == p[j])j++;
            pie[i] = j;
        }
        return pie;
    }
    
    int strStr(string haystack, string needle) {
        int sz = haystack.size();
        int psz = needle.size();
        if(psz>sz)return -1;
        if(haystack == "" and needle == "")return 0;
        vector<int> pie = lps(needle);
        int j = 0;
        for(int i = 0;i<sz;i++){
            while(haystack[i]!=needle[j] and j>0)j = pie[i-1];
            if(haystack[i] == needle[j])j++;
            
            if(j == psz)
                return i-psz+1;
        }
        return -1;
    }
};