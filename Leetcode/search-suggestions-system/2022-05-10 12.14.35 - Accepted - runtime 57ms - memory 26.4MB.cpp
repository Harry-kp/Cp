
class Solution {
public:
    
    int lower(vector<string>& a,string& key){
        
        int l = -1;
        int r = a.size();
        while(r-l>1){
            int m = (r+l)/2;
            if(key<=a[m]){
                 r=m;
            }
            else{
                l=m;
            }
                
            
        }
        return r;
    }
    
    bool compare(string& pre,string& b){
        for(int i = 0;i<pre.size();i++){
            if(pre[i]!=b[i])return false;
        }
        return true;
    }
    vector<vector<string>> suggestedProducts(vector<string>& p, string s) {
       
        string pre = "";
        sort(p.begin(),p.end());
        vector<vector<string>> res;
        for(auto c:s){
            pre+=c;
            
            int l = lower(p,pre);
            vector<string> tmp;
            for(int i = 0;i<3 and l+i<p.size();i++){
                if(compare(pre,p[l+i]))
                    tmp.push_back(p[l+i]);
                else
                    break;
            }
            
            res.push_back(tmp);
                    
        }
        return res;
    }
    
    
    
    
};