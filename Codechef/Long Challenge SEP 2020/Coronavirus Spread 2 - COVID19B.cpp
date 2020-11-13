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

vector<map<int,float>> adj_list;
vector<bool> v;

float is_div(int i,int v1,int j,int v2){
    if(v1-v2 <= 0)return -1;
    float temp = (float)(j-i)/(v1-v2);
    return temp;
    
}

int  bfs(int node){
    queue<pair<int,float>> q;
    q.push(MP(node,0));
    v[node] = true;
    int cou = 0;
    while(!q.empty()){
        int f = q.front().F;
        float time = q.front().S;
        q.pop();
        cou++;
        // cout<<f<<" ";

        for(auto i = adj_list[f].begin();i!=adj_list[f].end();i++){
            if(!v[i->F] and i->S>=time){
                q.push(MP(i->F,i->S));
                v[i->F] = true;
            }
        }

    }
    return cou;
}


int32_t main(){
    fastio ;
    int t;
    cin>>t;
    while(t--){
        int n,i,j;cin>>n;
        int Vel[n],ans[n];
        for(i = 0;i<n;i++)
            cin>>Vel[i];

        adj_list.assign(n,map<int,float>());
        

        for(i = 0;i<n-1;i++)
            for(j = i+1;j<n;j++){
                float temp = is_div(i,Vel[i],j,Vel[j]);
                    if(temp!=-1)
                    {   
                        adj_list[i][j] = temp;
                        adj_list[j][i] = temp;
                    }
                }
        


        for(i = 0;i<n;i++){
            for(auto y:adj_list[i]){
            }
        }

        for(i = 0;i<n;i++){
            v.assign(n,false);
            // cout<<i<<"-->";
            ans[i] = bfs(i);
        }

        int min1 = 10,max1 = -1;
        for(i = 0;i<n;i++){
            min1 = min(min1,ans[i]);
            max1 = max(max1,ans[i]);
        }
        cout<<min1<<" "<<max1<<endl;




    }
}
