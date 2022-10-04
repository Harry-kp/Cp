class Solution {
public:
    int dp[601][101][101];
    int solve(int i,int o,int z,const vector<vector<int>>& a){
    if(i == a.size() or(o == 0 and z == 0))
        return 0;
    
    if(dp[i][o][z]!=-1)return dp[i][o][z];
    if(a[i][0]>z or a[i][1]>o)
        return dp[i][o][z]=solve(i + 1, o, z, a);

    int in = 1 + solve(i + 1, o - a[i][1], z - a[i][0], a);
    int ex = solve(i + 1, o , z , a);
    // cout<<max(in,ex)<<'\n';
    return dp[i][o][z]=max(in, ex);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> a;

        string s;
        for (int i = 0; i < strs.size(); i++)
        {
            s=strs[i];
            int o = 0, z = 0;
            for (auto c : s)
            {
                c == '1' ? o++ : z++;
            }
            
            a.push_back({z, o});
        }
        memset(dp,-1,sizeof dp);
        return solve(0, n, m, a);
    }
};