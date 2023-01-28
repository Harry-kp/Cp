class Solution {
public:
    int threeSumClosest(vector<int>& a, int t) {
        sort(a.begin(),a.end());
        int n = a.size();
        
        int min1 = 99999999;
        int ans = 0,l,r,tmp;
        for(int i = 0;i<n;i++){
            l = i+1,
            r=n-1;
            
            while(l<r){
                tmp = a[i]+a[l]+a[r];
                if(tmp == t)return t;
                
                if(abs(tmp-t)<min1){
                    ans = tmp;
                    min1 = abs(tmp-t);
                }
                if(tmp>t)
                    r--;
                else
                    l++;
            }
        }
        return ans;
        
    }
};