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
 
	ll n, w;
	cin >> n >> w;
 
	ll wt[n];
	for (ll i = 0; i < n; i++) {
		cin >> wt[i];
	}
 
	if (n == 1) {
		if (wt[0] <= w) {
			cout << wt[0] << "\n";
		}
		else {
			cout << 0 << "\n";
		}
		return;
	}
 
 
	ll dp[n + 1][w + 1];
	memset(dp, 0, sizeof(dp));
 
	ll res = 0;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= w; j++) {
			dp[i][j] = dp[i - 1][j];
			if (wt[i - 1] <= j) {
 
				ll op1 = dp[i - 1][j];
				ll op2;
				if (i - 2 >= 0 && j - 2 > 0) {
					op2 = dp[i - 2][j - wt[i - 1]] + wt[i - 1];
				}
				else {
					op2 = wt[i - 1];
				}
				dp[i][j] = max(op1, op2);
				res = max(res, dp[i][j]);
			}
		}
	}
 
 
 
	cout << dp[n][w] << "\n";
 
 
 
 
 
 
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ll co = 0;
	w(t) {
		co += 1;
		cout << "Scenario #" << co << ": ";
		solve();
	}
	return 0;
} 