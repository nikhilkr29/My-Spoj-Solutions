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
 
 
ll dp[100005];
ll n;
ll solve1(ll a[], ll id) {
 
	if (id >= n) {
		return 0;
	}
 
	ll op1 = 0, op2 = 0, op3 = 0;
	if (dp[id] != -1) {
		return dp[id];
	}
 
	op1 = a[id];
	for (ll i = id; i < id + 2 && i < n; i++) {
		op2 += a[i];
	}
 
 
	for (ll i = id; i < id + 3 && i < n; i++) {
		op3 += a[i];
	}
 
 
	ll x = solve1(a, id + 2);
	ll y = solve1(a, id + 4);
	ll z = solve1(a, id + 6);
	op1 = x + op1;
	op2 = y + op2;
	op3 = z + op3;
 
	dp[id] = max({op1, op2, op3});
	return dp[id];
}
 
 
void solve() {
 
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
 
	if (n <= 3) {
		ll s = 0;
		for (ll i = 0; i < n; i++) {
			s += a[i];
		}
		cout << s << "\n";
		return;
	}
 
	cout << solve1(a, 0) << "\n";
 
 
 
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