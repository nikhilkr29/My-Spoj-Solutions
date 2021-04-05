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
#define  what_is(x) cerr << #x << " is " << x << endl;
#define  w(t) long long int t;cin>>t;while(t--)
 
 
 
void solve() {
 
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
 
	ll dp1[n], dp[n];
	memset(dp1, 0, sizeof(dp1));
	memset(dp, 0, sizeof(dp));
 
	dp1[0] = 1;
	for (ll i = 1; i < n; i++) {
		dp1[i] = 1;
		for (ll j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				dp1[i] = max(1 + dp1[j], dp1[i]);
			}
		}
	}
 
	dp[n - 1] = 1;
	for (ll i = n - 2; i >= 0; i--) {
		dp[i] = 1;
		for (ll j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				dp[i] = max(1 + dp[j], dp[i]);
			}
		}
	}
 
	ll res = 0;
	for (ll i = 0; i < n; i++) {
		res = max(res, dp[i] + dp1[i] - 1);
	}
 
	cout << res << "\n";
 
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	w(t) {
		solve();
	}
	return 0;
} 