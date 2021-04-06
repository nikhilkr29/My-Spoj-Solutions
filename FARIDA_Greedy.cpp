#include<bits/stdc++.h>
using namespace std;
#define  vi vector<long long int>
#define  set1 set<long long int>
#define  pb push_back
#define  map1 map<long long int,long long int>
#define  ll long long int
#define  mp make_pair
#define  inf 1e17
#define  minf INT_MIN
#define  setbits(x) __builtin_popcountll(x)
#define  pres(x,y) fixed<<setprecision(y)<<x
#define  pair1 pair<long long int,long long int>
#define  mk(arr,n,type) type *arr=new type[n];
#define  mod 1000000007
#define  pi  3.1415926535897932384626433832
#define  ins insert
#define  w(t) long long int t;cin>>t;while(t--)
 
 
 
void solve() {
 
	ll n;
	cin >> n;
 
	if (n == 0) {
		cout << 0 << "\n";
		return;
	}
 
	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
 
	ll inc = a[0];
	ll exc = 0, ninc, nexc;
	for (ll i = 1; i < n; i++) {
		ninc = exc + a[i];
		nexc = max(exc, inc);
		inc = ninc;
		exc = nexc;
	}
	cout << max(inc, exc) << "\n";
 
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ll c = 1;
	w(t) {
		cout << "Case " << c << ": ";
		solve();
		c += 1;
	}
	return 0;
} 
