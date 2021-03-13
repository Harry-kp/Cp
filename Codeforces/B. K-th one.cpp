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
     
     

struct segtree
{
    int size;
    vector<int> tree;

    void init(int n){
        size = 1;
        while(size<n){
            size*=2;
        }

        tree.assign(2*size,0);
    }

    void build(vector<int> &A){
        build(A,0,0,size);
    }

    void build(vector<int> &A,int x,int lx,int rx){

        if(rx-lx == 1){
            if(lx<(int)A.size()){
                tree[x] = A[lx];
            }
            return;
        }

        int m = (lx+rx)/2;

        build(A,2*x+1,lx,m);
        build(A,2*x+2,m,rx);

        tree[x] = tree[2*x+1] + tree[2*x+2];

    }

    void set(int i){
        set(i,0,0,size);
    }

    void set(int i,int x,int lx,int rx){
        if(rx-lx == 1){
            tree[x] = tree[x]^1;
            return;
        }

        int m = (lx+rx)/2;

        if(i<m){
            set(i,2*x+1,lx,m);
        }else{
            set(i,2*x+2,m,rx);
        }

        tree[x] = tree[2*x+1] + tree[2*x+2];
        
    }

    int query(int k){
        return query(k,0,0,size);
            
    }

    int query(int k,int x,int lx,int rx){
        if(rx-lx == 1)return lx;

        int m = (lx + rx)/2;

        if(k<=tree[2*x+1])
            return query(k,2*x+1,lx,m);
        else{
            return query(k-tree[2*x+1],2*x+2,m,rx);
        }
    }
};

int32_t main(){

    int n,m;
    cin>>n>>m;

    vector<int> A(n);

    for(int i = 0;i<n;i++)cin>>A[i];

    segtree st;
    st.init(n);

    st.build(A);

    int a,b;
    while(m--){
    cin>>a>>b;

    if(a == 1){
        st.set(b);
    }else{
        cout<<st.query(b+1)<<'\n';
    }
    }
}