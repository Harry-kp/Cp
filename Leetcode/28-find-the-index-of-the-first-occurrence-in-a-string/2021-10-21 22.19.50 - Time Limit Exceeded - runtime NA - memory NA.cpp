class Solution {
public:
    int strStr(string haystack, string needle) {
        int sz = haystack.size();
        int psz = needle.size();
        if(psz>sz)return -1;
        if(needle == "")return 0;
        
        vector<int> pie(psz);
        int j = 0;
        for(int i = 0;i<psz;i++){
            while(needle[i]!=needle[j] and j>0)j = pie[j-1];
            if(needle[i] == needle[j])j++;
            pie[i] = j;
        }
        
        
         j = 0;
        for(int i = 0;i<sz;i++){
            while(haystack[i]!=needle[j] and j>0)j = pie[j-1];
            if(haystack[i] == needle[j])j++;
            if(j == psz)return i-psz+1;
        }
        return -1;
    }
};