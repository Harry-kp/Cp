class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int t) {
        sort(b.begin(),b.end(),[](const vector<int>& a1,const vector<int>& a2){
           return a1[1]>a2[1]; 
        });
        
        int c = 0;
        for(int i = 0;i<b.size();i++){
            if(t-b[i][0]>0)
            {
                c+=b[i][1];
                t-=b[i][0];
            }
        }
        return c;
    }
};