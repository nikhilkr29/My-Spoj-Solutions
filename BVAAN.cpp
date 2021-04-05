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
 
ll k;
 
ll dp[102][102][102];
 
ll flag = 0;
 
ll solve(string s1, string s2, ll i, ll j, ll n, ll m, ll co) {
 
 
	if (co == 0) {
		return 0;
	}
 
	//Bahar aa gye hai
	if (i >= n || j >= m) {
		return minf;
	}
 
 
	if (dp[i][j][co] != -1) {
		return dp[i][j][co];
	}
 
 
	ll ans = 0;
 
	if (s1[i] == s2[j]) {
		ll op1 = int(s1[i]) + solve(s1, s2, i + 1, j + 1, n, m, co - 1);
		ll op2 = max(solve(s1, s2, i + 1, j, n, m, co), solve(s1, s2, i, j + 1, n, m, co));
		ans = max(op1, op2);
	}
	else {
		ll op3 = solve(s1, s2, i + 1, j, n, m, co);
		ll op4 = solve(s1, s2, i, j + 1, n, m, co);
		ans = max(op3, op4);
	}
 
 
 
	return dp[i][j][co] = ans;
 
}
 
void nk() {
 
	string s1, s2;
	cin >> s1 >> s2;
	ll n = s1.length(), m = s2.length();
	cin >> k;
	memset(dp, -1, sizeof(dp));
	ll ans = solve(s1, s2, 0, 0, n, m, k);
	if (ans < 0 ) {
		ans = 0;
	}
	cout << ans << "\n";
 
 
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