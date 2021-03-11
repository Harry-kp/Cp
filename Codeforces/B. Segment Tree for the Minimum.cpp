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
        vector<int> mins;
     
        void init(int n){
            size = 1;
            while(size<n)
                size *= 2;
            
            mins.assign(2*size,0);
        }
     
        void build(vector<int> &A,int x,int lx,int rx){
     
            if(rx-lx == 1){
                if(lx<(int)A.size()){
                    mins[x] = A[lx];
                }
                return;
            }
     
            int m = (lx + rx)/2;
            build(A,2*x+1,lx,m);
            build(A,2*x+2,m,rx);
            mins[x] = min(mins[2*x+1],mins[2*x+2]);
     
        }
     
        void build(vector<int> &A){
            build(A,0,0,size);
     
        }
     
        void set(int i,int v,int x,int lx,int rx){
     
            if(rx-lx == 1){
                mins[x] = v;
                return;
            }
     
            int m = (lx+ rx)/2;
            if(i<m)
                set(i,v,2*x+1,lx,m);
            else
                set(i,v,2*x + 2 ,m ,rx);
     
            mins[x] = min(mins[2*x+1],mins[2*x+2]);
            
        }
     
        void set(int i,int v){
            set(i,v,0,0,size);
        }
     
        int min_query(int l,int r,int x,int lx,int rx){
            
            if(lx>= r || rx<=l)
                return INT_MAX;
     
            if(lx>=l && rx<=r)return mins[x];
     
            int m = (lx + rx)/2;
     
            return min(min_query(l,r,2*x+1,lx,m),min_query(l,r,2*x+2,m,rx));
        }
     
        int min_query(int l,int r){
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
     
        int a,b,c;
        while(m--){
            cin>>a>>b>>c;
     
            if(a == 1){
                st.set(b,c);
            }else{
                cout<<st.min_query(b,c)<<'\n';
            }
        }
    }