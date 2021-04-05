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
 
 
ll dp[1005][1005];
 
ll solve(ll a[], ll st, ll e) {
 
	if (st >= e) {
		return 0;
	}
 
	if (dp[st][e] != -1) {
		return dp[st][e];
	}
 
	ll mx1 = max(a[st + 1], a[e]);
	ll mx2 = max(a[st], a[e - 1]);
	ll op1 = a[st];
 
 
	if (a[st + 1] == mx1) {
		op1 += solve(a, st + 2, e);
	}
	else {
		op1 += solve(a, st + 1, e - 1);
	}
 
	ll op2 = a[e];
	if (a[st] == mx2) {
		op2 += solve(a, st + 1, e - 1);
	}
	else {
		op2 += solve(a, st, e - 2);
	}
 
	return dp[st][e] = max(op1, op2);
 
}
 
 
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
 
 
	ll tc;
	ll co = 0;
	while (cin >> tc && tc != 0) {
 
		co++;
		cout << "In game " << co << ", the greedy strategy might lose by as many as ";
 
		ll a[tc];
		ll s = 0;
		for (ll i = 0; i < tc; i++) {
			cin >> a[i];
			s += a[i];
		}
		memset(dp, -1, sizeof(dp));
		ll res =	solve(a, 0, tc - 1);
		ll rem = s - dp[0][tc - 1];
		cout << res - rem << " points.\n";
 
 
 
	}
 
 
 
 
	return 0;
} 