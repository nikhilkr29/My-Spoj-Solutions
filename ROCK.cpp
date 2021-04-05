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
 
 
ll dp[205][205];
 
bool isvalid(string &s, ll i, ll j) {
 
	ll cone = 0, cz = 0;
	for (ll id = i; id <= j; id++) {
		if (s[id] == '0') {
			cz++;
		}
		else {
			cone++;
		}
	}
	if (cone > cz) {
		return true;
	}
	return	false;
 
}
 
 
ll res = 0;
 
ll solve(string &s, ll i, ll j) {
 
	if (i == j) {
		if (s[i] == '1') {
			return 1;
		}
		return 0;
	}
 
 
 
	if (i > j) {
		return 0;
	}
 
 
 
	if (isvalid(s, i, j)) {
		return j - i + 1;
	}
 
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
 
 
	ll mx = minf;
	for (ll k = i; k < j; k++) {
		ll lp = solve(s, i, k);
		ll rp = solve(s, k + 1, j);
		ll temp = max({lp, rp, lp + rp});
		mx = max(mx, temp);
	}
 
	return dp[i][j] = mx;
 
}
 
void nk() {
 
	ll n;
	cin >> n;
	string s;
	cin >> s;
	res = 0;
	memset(dp, -1, sizeof(dp));
	cout << solve(s, 0, s.length() - 1) << "\n";
 
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