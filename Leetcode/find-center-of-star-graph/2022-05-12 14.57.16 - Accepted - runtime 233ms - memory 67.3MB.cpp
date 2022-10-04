class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
        auto e1 = e[0];
        auto e2 = e[1];
        
        if(e1[0] == e2[0] or e1[0] == e2[1])
            return e1[0];
        return e1[1];
        
    }
};