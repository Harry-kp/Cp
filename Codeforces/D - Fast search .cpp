#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)


// A[i]>=x min i, Here key is l value
int function1(vector<int> &A,int key){
    int l = -1,r = A.size();

    while(r-l>1){
        int m = (r+l)/2;

        if(A[m]>=key)
            r=m;
        else
            l=m;
    }
    return r;
}


// A[i]<=x max i ,Here key is r value
int function2(vector<int> &A,int key){
    int l = -1,r = A.size();

    while(r-l>1){
        int m = (r+l)/2;

        if(A[m]<=key)
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
    // cin >> t;
    while (t--)
    {
        int n,k,l,r;
        cin>>n;
        vector<int> A(n);

        for(int i = 0;i<n;i++)
            cin>>A[i];
        sort(A.begin(),A.end());

        cin>>k;
        for(int i = 0;i<k;i++){
            cin>>l>>r;
            cout<<function2(A,r)-function1(A,l)+1<<((i<(k-1))?' ':'\n');
        }
    }
}
