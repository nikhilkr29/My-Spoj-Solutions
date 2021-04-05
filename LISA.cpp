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
 
ll dp[105][105];
ll dp1[105][105];
 
 
ll solve(string &s, ll i, ll j) {
 
 
	if (i > j) {
		return 0;
	}
	if (i == j) {
		return s[i] - '0';
	}
 
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
 
	ll mn = minf;
 
	for (ll k = i + 1; k < j; k += 2) {
		ll lp = solve(s, i, k - 1);
		ll rp = solve(s, k + 1, j);
		ll temp;
		if (s[k] == '*') {
			temp = lp * rp;
		}
		else {
			temp = lp + rp;
		}
		mn = max(mn, temp);
	}
 
	return dp[i][j] = mn;
}
 
 
ll solve1(string &s, ll i, ll j) {
 
 
	if (i > j) {
		return 0;
	}
	if (i == j) {
		return s[i] - '0';
	}
 
	if (dp1[i][j] != -1) {
		return dp1[i][j];
	}
 
	ll mn = inf;
 
	for (ll k = i + 1; k < j; k += 2) {
		ll lp = solve1(s, i, k - 1);
		ll rp = solve1(s, k + 1, j);
		ll temp;
		if (s[k] == '*') {
			temp = lp * rp;
		}
		else {
			temp = lp + rp;
		}
		mn = min(mn, temp);
	}
 
	return dp1[i][j] = mn;
 
}
 
 
 
void nk() {
 
	string s;
	cin >> s;
	memset(dp, -1, sizeof(dp));
 
	memset(dp1, -1, sizeof(dp1));
	cout << solve(s, 0, s.length() - 1) << " " << solve1(s, 0, s.length() - 1) << "\n";
 
 
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	w(t) {
		nk();
	}
	return 0;
} 