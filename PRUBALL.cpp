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
 
ll dp[55][1005];
 
ll eggdrop(ll n, ll k) {
 
	if (n == 1) {
		return k;
	}
	if (k == 0 || k == 1) {
		return k;
	}
	if (dp[n][k] != -1) {
		return dp[n][k];
	}
 
	ll ans = inf;
	for (ll i = 1; i <= k; i++) {
		ll op1 = 1 + eggdrop(n - 1, i - 1);   //Egg break
		ll op2 = 1 + eggdrop(n, k - i);       //Egg Didn't Break
		ll worstofboth = max(op1, op2);
 
		ans = min(ans, worstofboth);
	}
 
	return dp[n][k] = ans;
 
 
 
}
 
void solve() {
 
	ll q, n, k;
	cin >> q >> n >> k;
	memset(dp, -1, sizeof(dp));
	cout << q << " " << eggdrop(n, k) << "\n";
 
 
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