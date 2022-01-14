#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

string a,b;
pair<int,string> dp[20][2][2][2];

pair<int,string> maxa(pair<int,string> A,pair<int,string> B,int j,int start){
    int mul = (start == 0 and j == 0)?1:j;

    if((B.first * mul)>A.first){
        A.first = B.first * mul;
        A.second = char(j + '0') + B.second;
    }

    return A;

}

pair<int,string> solve(int pos,int t1,int t2,int start){
    if(pos == a.size())
        return {1,""};

    if(dp[pos][t1][t2][start].first!=-1)
        return dp[pos][t1][t2][start];
    
    int lb = t1?a[pos]-'0':0;
    int ub = t2?b[pos] - '0':9;

    pair<int,string> ans = {-1,""};

    for(int j = lb;j<=ub;j++){
        
        ans = maxa(ans,solve(pos+1,t1&(j==lb),t2&(j==ub),start|(j>0)),j,start);
        
    }
    return dp[pos][t1][t2][start] = ans;        
}

void appendzero(){
    reverse(a.begin(),a.end());
    while(a.size()<b.size())
        a.push_back('0');
    reverse(a.begin(),a.end());
}

void ps(string ans){
    int i = 0;
        while(ans[i] == '0')i++;

        while(i<ans.size()){
            cout<<ans[i];
            i++;
        }
        cout<<'\n';
}

int32_t main()
{
    
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        cin>>a>>b;
        appendzero();
        //init dp
        for(int i = 0;i<20;i++)for(int j = 0;j<2;j++)for(int k = 0;k<2;k++)
        dp[i][j][k][0] = dp[i][j][k][1] = {-1,""};

        pair<int,string> ans = solve(0,1,1,0);
        ps(ans.second);
    }
}
