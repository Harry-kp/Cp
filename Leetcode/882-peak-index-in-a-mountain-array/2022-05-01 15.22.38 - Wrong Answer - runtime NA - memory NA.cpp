class Solution {
public:
    
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int l =  1;
        int r = arr.size();
        
        while(l+1<r){
            int m = (l+r)/2;
            
            if(arr[m]<arr[m+1])
                l=m;
            else
                r=m;
        }
        return l;
    }
};