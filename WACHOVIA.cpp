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
 
	ll w, n;
	cin >> w >> n;
	ll dp[n + 1][w + 1];
	ll wt[n + 1], val[n + 1];
	memset(dp, 0, sizeof(dp));
 
	for (ll i = 0; i < n; i++) {
		cin >> wt[i] >> val[i];
	}
 
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= w; j++) {
			if (wt[i - 1] <= j) {
				dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][w] << ".\n";
 
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	w(t) {
		cout << "Hey stupid robber, you can get ";
		solve();
	}
	return 0;
} 