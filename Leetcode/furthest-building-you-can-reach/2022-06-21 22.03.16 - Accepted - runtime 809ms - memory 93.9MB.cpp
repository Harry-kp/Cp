class Solution {
public:
    bool check(int m,const vector<int>& h,const int& l,int b){
        vector<int> diff;
        for(int i = 1;i<=m;i++){
            if(h[i]-h[i-1]>0)
                diff.push_back(h[i]-h[i-1]);
        }
        
        sort(diff.begin(),diff.end());
        reverse(diff.begin(),diff.end());
        
        for(int i = l;i<diff.size();i++){
            if(b<diff[i])return false;
            b-=diff[i];
        }
        return true;
    }
    int furthestBuilding(vector<int>& h, int b, int lad) {
        int l = -1;
        int r = h.size();
        
        while(r-l>1){
            int m = (r+l)/2;
            
            if(check(m,h,lad,b))
                l=m;
            else
                r=m;
        }
        return l;
    }
};