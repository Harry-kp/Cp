class Solution {
public:
    
    string minWindow(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();
        int str[256]{},pat[256]{};
        int l = 0,min_len = INT_MAX,start = -1;
        
        if(l1<l2)return "";
        
        for(int i = 0;i<l2;i++)pat[t[i]]++;
        
        int cnt = 0;
        for(int i = 0;i<l1;i++){
            str[s[i]]++;
            
            if(str[s[i]]<=pat[s[i]])
                cnt++;
            
            //substring found
            if(cnt == l2){
                
                //minimize it
                while(str[s[l]]>pat[s[l]]){
                    
                    if(str[s[l]]>pat[s[l]])
                        str[s[l]]--;
                    l++;
                }
            
            
            int len = i-l+1;
            
            if(min_len>len){
                start = l;
                min_len = len;
            }
            
        }
        
        
    }
        if(start == -1)return "";
        return s.substr(start,min_len);
    }
          
};