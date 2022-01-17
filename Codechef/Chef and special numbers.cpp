#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long int

//FOR 30 PTS:- mod is 2520 which is lcm 2 3 4 5 6 7 8 9 ,,because in the end we need to know the mod with each number which can be calculated from mod[2520] value

// FOR 100 PTS:- handle 5 case separately now lcm become 504 and divisibility by 5 can be assured by storing bool which is true if last digit is 5 or 0
int dp[20][2][513][505][2];
int k;
vector<int> digit;

int solve(int pos,int t1,int mask,int  mod,int five){
    if(dp[pos][t1][mask][mod][five]!=-1)return dp[pos][t1][mask][mod][five];
    if(pos == digit.size()){
        int cnt = 0;
        for(int i = 1;i<=9;i++)
            if(i!=5)
                if((mask&(1<<(i-1)))!=0 and (mod%i == 0))cnt++;
        
        if((mask&(1<<4))!=0 and five)cnt++;
        return dp[pos][t1][mask][mod][five] = (cnt>=k);
    }

    

    int ans = 0;
    int ub = t1?digit[pos]:9;

    for(int j = 0;j<=ub;j++){
        if(j == 0)
            ans+=solve(pos+1,t1&(j==ub),mask,(mod*10)%504,1);
        else
            ans+=solve(pos+1,t1&(j==ub),mask|(1<<(j-1)),(mod*10+j)%504,(j == 5));
    }
    return dp[pos][t1][mask][mod][five] = ans;
}

int getSpecial(int n){
    digit.clear();
    memset(dp,-1,sizeof dp);
    while(n){
        digit.push_back(n%10);
        n/=10;
    }
    reverse(digit.begin(),digit.end());
    return solve(0,1,0,0,1);
}
int32_t main()
{
    
    fastio;
    int t = 1;
    cin >> t;
    int a,b;
    while (t--)
    {
        cin>>a>>b>>k;
        int r = getSpecial(b);
        int l = getSpecial(a-1);
        cout<<r-l<<'\n';
    }
}
