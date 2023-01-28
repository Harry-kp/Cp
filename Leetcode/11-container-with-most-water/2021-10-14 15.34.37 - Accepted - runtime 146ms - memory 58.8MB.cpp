class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0,sh;
        int l = 0,r = height.size()-1;
        
        while(l<r){
            sh = min(height[l],height[r]);
            area = max(area,(r-l)*sh);
            
            if(height[l] == sh)
                l++;
            else
                r--;
        }
        return area;
    }
};