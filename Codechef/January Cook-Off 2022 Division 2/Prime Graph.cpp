#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define EB emplace_back
#define MOD 1000000007
#define int long long int
#define S second
#define F first
#define debug1 cout << "debug1" << '\n'
#define debug2 cout << "debug2" << '\n'
#define debug3 cout << "debug3" << '\n'


// int dr[] = {0,-1,0,1,-1,-1,1,1};
// int dc[] = {-1,0,1,0,-1,1,1,-1};


// Maths Utils
int binExp(int a, int b, int m){int r = 1;while (b){if (b % 2 == 1)r = (r * a) % m;a = (a * a) % m;b = b / 2;}return r;}

int modinv(int x,int m){
    return binExp(x,m-2,m);
}


#define MAX 1000000

vector<int> primes;

void Sieve()
{
	int n = MAX;
	int nNew = sqrt(n);
	int marked[n/2+500] = {0};

	for (int i=1; i<=(nNew-1)/2; i++)
		for (int j=(i*(i+1))<<1; j<=n/2; j=j+2*i+1)
			marked[j] = 1;

	primes.push_back(2);

	for (int i=1; i<=n/2; i++)
		if (marked[i] == 0)
			primes.push_back(2*i + 1);
}

int binarySearch(int left,int right,int n)
{
	if (left<=right)
	{
		int mid = (left + right)/2;

		if (mid == 0 || mid == primes.size()-1)
			return primes[mid];

		if (primes[mid] == n)
			return primes[mid-1];
		if (primes[mid] < n && primes[mid+1] > n)
			return primes[mid];
		if (n < primes[mid])
			return binarySearch(left, mid-1, n);
		else
			return binarySearch(mid+1, right, n);
	}
	return 0;
}

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}

int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    cin >> t;
    Sieve();
    while (t--)
    {
        int n;
        cin>>n;

        int np;
        if(isPrime(n-1)){
            cout<<(n*(n-1))/2<<'\n';
            continue;
            }

        np = binarySearch(0, primes.size()-1, n-1);
        
        if(n%2 == 0)
            cout<<(np*n)/2<<'\n';
        else
            cout<<(np*(n-1))/2+1<<'\n';
    }
}



