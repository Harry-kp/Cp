#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long int

int hb,hs,hc;
int nb,ns,nc;
int pb,ps,pc;
int r;
string rec;


bool good(int ham){

    if(ham * hb<=nb and ham*hs<=ns and ham*hc<=nc)
        return true;
    
    // ingredients that need to be purchased
    int wb = (ham*hb - nb>=0)?ham*hb - nb:0;
    int ws = (ham*hs - ns>=0)?ham*hs - ns:0;
    int wc = (ham*hc - nc>=0)?ham*hc - nc:0;

    return wb*pb + ws*ps + wc*pc<=r;
}

int solve(){
    int l = 0;
    int r = 1;
    while(good(r))r*=2;

    while(l+1<r){
        int m = (l+r)/2;

        if(good(m))
            l=m;
        else
            r=m;
    }
    return l;
}

int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {   
        hb=hc=hc=0;
        cin>>rec;
        for(auto x:rec){
            if(x == 'B')
                hb++;
            else if(x == 'S')
                hs++;
            else
                hc++;
        }

        cin>>nb>>ns>>nc;
        cin>>pb>>ps>>pc;
        cin>>r;

        cout<<solve()<<'\n';
    }
}
