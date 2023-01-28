class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int m = 201;
        for(int i = 0;i<n;i++)
            m = m<strs[i].size()?m:strs[i].size();
        
        string ans = "";
        int i = 0;
        while(i<m){
            for(int j = 1;j<n;j++){
                if(strs[j][i] != strs[j-1][i])
                    return ans;
            }
            ans = ans + strs[0][i];
            i++;
        }
        return ans;
        
    }
};