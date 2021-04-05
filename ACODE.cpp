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
 
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
 
	string  s;
	while (cin >> s && s != "0") {
 
		ll n = s.size();
		ll dp[n];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (ll i = 1; i < n; i++) {
			if (s[i] - '0' > 0) {
				dp[i] = dp[i - 1];
			}
			ll val = (s[i - 1] - '0') * 10 + (s[i] - '0');
			if (val >= 10 && val <= 26) {
				if (i < 2) {
					dp[i] += dp[0];
				}
				else {
					dp[i] += dp[i - 2];
				}
			}
		}
		cout << dp[n - 1] << "\n";
	}
	return 0;
} 