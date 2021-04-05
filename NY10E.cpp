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
 
ll dp[1005][10]; // dp[i][j] is count of all numbers with digit i and having
// leading digits as j
 
void solve() {
 
	ll x, n;
	cin >> x >> n;
	cout << x << " " << dp[n][0] << "\n";
 
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
 
 
	for (ll i = 0; i < 1005; i++) {
		dp[i][9] = 1;
	}
 
	for (ll i = 0; i <= 9; i++) {
		dp[0][i] = 1;
	}
 
	for (ll i = 1; i <= 1005; i++) {
		for (ll j = 8; j >= 0; j--) {
			dp[i][j] = dp[i - 1][j] + dp[i][j + 1];
		}
	}
 
 
	w(t) {
		solve();
	}
	return 0;
} 