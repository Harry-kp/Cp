#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long int

int n;
string a,b;
vector<int> alpa(26,0);
vector<int> alpb(26,0);
int A[200000+10];


bool can_delete(int ub){
    
    unordered_set<int> del;

    for(int i = 0;i<=ub;i++){
        del.insert(A[i]-1);
    }
    int i = 0,j = 0;
    while(i<a.size() and j<b.size())
        if(del.find(i)==del.end()){
            if(a[i] == b[j])
            {
                i++;j++;
            }
            else
                i++;
        }else
            i++;
    return j == b.size();
}


int solve(){
    int l = -1;
    int r = n;
    while(l+1<r){
        int m = (l+r)/2;
        if(can_delete(m))
            l=m;
        else
            r=m;
    }
    return l;
}

int32_t main()
{

    fastio;
    int t = 1;
    while (t--)
    {   
        cin>>a>>b;
        for(auto x:a)
            alpa[x-'a']++;
        for(auto x:b)
            alpb[x-'a']++;
        n = a.size();
        for(int i = 0;i<n;i++)cin>>A[i];
        cout<<solve()+1<<'\n';
    }
}
