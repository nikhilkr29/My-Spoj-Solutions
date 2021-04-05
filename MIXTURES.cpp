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
#define  w(t) long long int t;t=1;while(t--)
 
ll n;
 
ll dp[102][102];
 
ll csum(ll a[], ll s, ll e) {
 
	ll res = 0;
	for (ll i = s; i <= e; i++) {
		res += a[i];
		res %= 100;
	}
	return res;
}
 
ll mcm(ll a[], ll i, ll j) {
 
	if (i >= j) {
		return 0;
	}
 
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
 
	ll ans = inf;
	for (ll k = i; k < j; k++) {
		ll op = mcm(a, i, k) + mcm(a, k + 1, j) + (csum(a, i, k) * csum(a, k + 1, j));
		ans = min(ans, op);
	}
	return dp[i][j] = ans;
 
}
 
void solve() {
 
	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
 
	memset(dp, -1, sizeof(dp));
 
//i to k-1 and  k to j
 
	cout << mcm(a, 0, n - 1) << "\n";
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	while (cin >> n && n != EOF) {
		solve();
	}
	return 0;
} 
