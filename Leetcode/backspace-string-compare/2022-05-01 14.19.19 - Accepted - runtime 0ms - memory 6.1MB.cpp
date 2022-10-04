class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1;
        int j = t.size()-1;
        int skips = 0;
        int skipt = 0;
        
        while(i>=0 or j>=0){
            while(i>=0){
                if(s[i] == '#'){skips++;i--;}
                else if(skips){skips--;i--;}
                else break;
            }
            while(j>=0){
                if(t[j] == '#'){skipt++;j--;}
                else if(skipt){skipt--;j--;}
                else break;
            }
            
            
            if(i>=0 and j>=0 and s[i] != t[j])return false;
            if((i>=0)!=(j>=0))return false;
            
            i--;j--;
        }
        return true;
    }
};