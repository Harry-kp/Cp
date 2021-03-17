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
            if(rx - lx == 1){
                if(lx<(int)A.size())
                    tree[x] = A[lx];
                return ;
            }

            int m = (lx+rx)/2;

            build(A,2*x+1,lx,m);
            build(A,2*x+2,m,rx);

            tree[x] = max(tree[2*x+1],tree[2*x+2]);

        }

        void set(int i,int v){
            set(i,v,0,0,size);
        }

        void set(int i,int v,int x, int lx,int rx){
            if(rx-lx == 1){
                tree[x]  = v;
                return;

            }

            int m = (lx+rx)/2;

            if(i<m){
                set(i,v,2*x+1,lx,m);

            }else{
                set(i,v,2*x+2,m,rx);
            }

            tree[x] = max(tree[2*x+1],tree[2*x+2]);

        }

        int query(int q){
            return query(q,0,0,size,0,size);
        }

        int query(int q,int x,int lx,int rx,int l,int r){

            if(tree[x]<q)return -1;
            if(rx - lx == 1){
                // if(tree[lx]<q)return -1;

                return lx;
            }

            int m  = (lx+rx)/2;

            if(tree[2*x + 1]>=q)
                return query(q,2*x+1,lx,m,l,r);
            else
                return query(q,2*x+2,m,rx,l,r);
            

        }
    };

    int32_t main(){
        int n,m,a,b,c;
        

        cin>>n>>m;
        vector<int> A(n);
        segtree st;

        st.init(n);
        for(int i = 0;i<n;i++){
            cin>>A[i];
        }
        st.build(A);

        // for(int i = 0;i<2* st.size;i++){
        //     cout<<st.tree[i]<<" ";
        // }
        for(int i = 0;i<m;i++){
            cin>>a;

            if(a == 1){
                cin>>b>>c;
                st.set(b,c);
            }
            else{
                cin>>b;
            cout<<st.query(b)<<'\n';
            }
        }
        // for(int i = 0;i<2* st.size;i++){
        //     cout<<st.tree[i]<<" ";
        // }

    }