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
 
ll dp[2005][2005];
ll n, m;
 
ll solve1(string &s, string &p, ll i, ll j) {
 
	if (i == n) {
		return m - j;
	}
	if (j == m) {
		return n - i;
	}
 
 
 
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
 
	ll ans;
	if (s[i] == p[j]) {
		ans = solve1(s, p, i + 1, j + 1);
	}
 
	else {
		//Add
		ll op1 = 1 + solve1(s, p, i, j + 1);
		//Replace
		ll op2 = 1 + solve1(s, p, i + 1, j + 1);
		//Delete
		ll op3 = 1 + solve1(s, p, i + 1, j);
		ans = min({op1, op2, op3});
	}
 
 
 
	return dp[i][j] = ans;
 
}
 
void solve() {
 
	string s, p;
	cin >> s >> p;
	n = s.length();
	m = p.length();
	memset(dp, -1, sizeof(dp));
 
	cout << solve1(s, p, 0, 0) << "\n";
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