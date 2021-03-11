#include <bits/stdc++.h>
using namespace std;
 
#define fastio           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define PI(a,b)          pair<a,b>
#define MP               make_pair
#define EB               emplace_back
#define MOD              1000000007
#define int              long long
#define S                second
#define F                first
#define endl             '\n'
#define FOR(var,len)     for(var = 0;var<len;var++)
#define debug1           cout<<"debug1"<<'\n'
#define debug2           cout<<"debug2"<<'\n'
#define debug3           cout<<"debug3"<<'\n'
#define max_l            1000005



struct segtree{

    int size;
    vector<pair<int,int>> mins;

    void init(int n){
        size = 1;
        while(size<n)
            size *= 2;
        
        mins.assign(2*size,make_pair(0,0));
    }

    void build(vector<int> &A,int x,int lx,int rx){

        if(rx-lx == 1){
            if(lx<(int)A.size()){
                mins[x].F = A[lx];
                mins[x].S = 1;
            }
            return;
        }

        int m = (lx + rx)/2;
        build(A,2*x+1,lx,m);
        build(A,2*x+2,m,rx);

        if(mins[2*x+1].F == mins[2*x + 2].F){
            mins[x].F = mins[2*x+1].F;
            mins[x].S = mins[2*x+1].S + mins[2*x+2].S;
        }
        else{
            mins[x] = mins[2*x+1].F<mins[2*x+2].F?mins[2*x+1]:mins[2*x+2];
        }

    }

    void build(vector<int> &A){
        build(A,0,0,size);

    }

    void set(int i,int v,int x,int lx,int rx){

        if(rx-lx == 1){
            mins[x].F = v;
            mins[x].S = 1;
            return;
        }

        int m = (lx+ rx)/2;
        if(i<m)
            set(i,v,2*x+1,lx,m);
        else
            set(i,v,2*x + 2 ,m ,rx);

        if(mins[2*x+1].F == mins[2*x + 2].F){
            mins[x].F = mins[2*x+1].F;
            mins[x].S = mins[2*x+1].S + mins[2*x+2].S;
        }
        else
            mins[x] = mins[2*x+1].F<mins[2*x+2].F?mins[2*x+1]:mins[2*x+2];
        
    }

    void set(int i,int v){
        set(i,v,0,0,size);
    }

    pair<int,int> min_query(int l,int r,int x,int lx,int rx){
        
        if(lx>= r || rx<=l)
            return make_pair(INT_MAX,0);

        if(lx>=l && rx<=r)return mins[x];

        int m = (lx + rx)/2;

        pair<int,int> min1 = min_query(l,r,2*x+1,lx,m);
        pair<int,int> min2 = min_query(l,r,2*x+2,m,rx);
        
        if(min1.F == min2.F){
            min1.S = min1.S + min2.S;
            return min1;
        }
        else
            return min1.F<min2.F?min1:min2;
    }

    pair<int,int> min_query(int l,int r){
        return min_query(l,r,0,0,size);
    }

};



int32_t main(){
    
    int n,m;
    cin>>n>>m;
    vector<int> A(n);

    for(int i = 0;i<n;i++)
        cin>>A[i];
    
    segtree st;
    st.init(n);
    st.build(A);

    // for(int i = 0;i<st.mins.size();i++)
    // cout<<st.mins[i].F<<" "<<st.mins[i].S<<'\n';

    int a,b,c;
    while(m--){
        cin>>a>>b>>c;

        if(a == 1){
            st.set(b,c);
        }else{
            pair<int,int> ans;
            ans = st.min_query(b,c);
            cout<<ans.F<<" "<<ans.S<<'\n';
        }
    }
}