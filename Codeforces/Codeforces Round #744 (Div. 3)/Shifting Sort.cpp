	#include <bits/stdc++.h>
	using namespace std;

	#define fastio                    \
	    ios_base::sync_with_stdio(0); \
	    cin.tie(NULL);                \
	    cout.tie(NULL)
	#define PI(a, b) pair<a, b>
	#define MP make_pair
	#define EB emplace_back
	#define MOD 1000000007
	#define int long long int
	#define S second
	#define F first
	#define FOR(var, len) for (var = 0; var < len; var++)
	#define debug1 cout << "debug1" << '\n'
	#define debug2 cout << "debug2" << '\n'
	#define debug3 cout << "debug3" << '\n'


	// int dr[] = {0,-1,0,1,-1,-1,1,1};
	// int dc[] = {-1,0,1,0,-1,1,1,-1};


	// Maths Utils
	int binExp(int a, int b, int m){int r = 1;while (b){if (b % 2 == 1)r = (r * a) % m;a = (a * a) % m;b = b / 2;}return r;}

	int32_t main()
	{
	    // freopen("input.txt","r",stdin);
	    // freopen("output.txt","w",stdout);
	    fastio;
	    int t = 1;
	    cin >> t;

	    //Main observation is selection sort takes minimum number of swaps to sort an array  .Hence , the maximum shift will be atmost n
	    while (t--)
	    {
		int n;
		cin>>n;
		int A[n];

		for(int i = 0;i<n;i++)
		    cin>>A[i];
		vector<vector<int>> ans;
		int k=0;
		for(int i = n-1;i>=0;i--){
		    int min_ind = i;
		    for(int j = 0;j<=i;j++){
		        if(A[j]>A[min_ind]){
		            min_ind = j;
		        }
		    }
		    if(i!=min_ind){
		        k++;
		        ans.push_back({min_ind+1,i+1,1});
		        for(int l = min_ind;l<i;l++)
		            swap(A[l],A[l+1]);
		    }
		    

		}
		cout<<k<<'\n';
		for(auto x:ans){
		    cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<'\n';
		}
	    }
	}
