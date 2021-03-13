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
        vector<tuple<int,int,int,int>> tree;

        void init(int n){
            size = 1;
            while(size<n)
                size *=2;
            
            // {0,0,0,0} seg_sum,pref,suff,sum
            tree.assign(2*size,{0,0,0,0});
        }
        tuple<int,int,int,int> assignParentValue(tuple<int,int,int,int> l,tuple<int,int,int,int> r){

            int seg,p,s,sum1;
            seg = max(max(get<0>(l), get<0>(r)),get<2>(l) + get<1>(r));
            sum1 = get<3>(l) + get<3>(r);
            p = max(get<1>(l),get<3>(l) + get<1>(r));
            s = max(get<2>(r),get<3>(r) + get<2>(l));

            return {seg,p,s,sum1};

        }
        tuple<int,int,int,int> leafInitialValue(int x){
            int seg,p,s,sum1;
            if(x<=0){
                seg = 0;
                p = x;
                s = x;
                sum1 = x;
                return {seg,p,s,sum1};
            }
            else{
                seg = x;
                p = x;
                s = x;
                sum1 = x;
                return {seg,p,s,sum1};
            }
        }

        void build(vector<int> &A){
            build(A,0,0,size);
        }

        void build(vector<int> &A,int x,int lx,int rx){
            
            if(rx-lx == 1){
                if(lx<(int)A.size())
                    tree[x] = leafInitialValue(A[lx]);
                    return;
            }

            int m = (lx+rx)/2;

            build(A,2*x+1,lx,m);
            build(A,2*x+2,m,rx);

            tree[x] = assignParentValue(tree[2*x+1],tree[2*x+2]);

        }

        void set(int i,int v){
            set(i,v,0,0,size);
        }

        void set(int i,int v,int x,int lx,int rx){

            if(rx - lx == 1){
                tree[x] = leafInitialValue(v);
                return;
            }

            int m = (lx+rx)/2;

            if(i<m){
                set(i,v,2*x+1,lx,m);
            }
            else{
                set(i,v,2*x+2,m,rx);
            }

            tree[x] = assignParentValue(tree[2*x+1],tree[2*x+2]);
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
     
        int i,v;
        
        do{
            cout<<get<0>(st.tree[0])<<'\n';
            cin>>i>>v;

            st.set(i,v);

        }
        while(m--);
    }