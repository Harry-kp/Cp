class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const auto& x,const auto& y){
            if(x[0]>y[0])return true;
            else if(x[0] == y[0])
                return x[1]<y[1];
            return false;
        });
        int n = people.size();
        vector<vector<int>> res;
        
        for(auto x:people){
            res.insert(res.begin()+x[1],x);
        }
        return res;
    }
};

// 4.4,5.0,5.2,6.1,7.0,7.1