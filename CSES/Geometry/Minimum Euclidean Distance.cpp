// O(N*log^2(N))

#include<bits/stdc++.h>
#define int long long int
using namespace std;
 
unsigned int MAX  = 8000000000000000000 + 5;
struct P{
    int x,y;
};
 
int sq(int a){return a*a;}
 
int euclid(P& a,P& b){
    int ans = sq(a.x - b.x) + sq(a.y - b.y);
    return ans;
}
 
int distance(vector<P> points){
    int n = points.size();
 
    if(n == 1)
        return MAX;
    
    vector<P> left = vector<P>(points.begin(),points.begin()+n/2);
    vector<P> right = vector<P>(points.begin()+n/2,points.end());
 
    int d1 = distance(left);
    int d2 = distance(right);
    int d = min(d1,d2);
    int mid_x = left.back().x;
 
    vector<P> stripe;
    
    for(auto a:left){
        if(d>sq(a.x-mid_x))
            stripe.push_back(a);
    }
 
    for(auto a:right){
        if(d>sq(mid_x-a.x))
            stripe.push_back(a);
    }
 
    sort(stripe.begin(),stripe.end(),[&](const P& a,const P& b){
        return a.y< b.y;
    });
    for(int i = 0;i<(int)stripe.size();i++){
        for(int j = i+1;j<(int)stripe.size() && sq(stripe[j].y-stripe[i].y)<d;j++)
        {
        d = min(d,euclid(stripe[i],stripe[j]));}
    }
 
    return d;
 
}
int32_t main(){
 
    int n;cin>>n;
    vector<P> point(n);
    for(int i = 0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        point[i].x = x;
        point[i].y = y;
    }
 
    sort(point.begin(),point.end(),[&](const P& a,const P& b){
        return a.x< b.x;
    });
    cout<<distance(point)<<'\n';
}
