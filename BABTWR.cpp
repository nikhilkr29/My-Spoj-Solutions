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
 
ll n;
 
struct s
{
	ll h, l, w;
 
};
 
bool comp(s p1, s p2) {
 
	if (p1.l * p1.w == p2.l * p2.w) {
		return p1.h < p2.h;
	}
	return p1.l * p1.w < p2.l * p2.w;
}
 
void solve() {
 
	vector<s> v(3 * n);
	ll co = 0;
	for (ll i = 0; i < n; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		v[co].h = a;
		v[co].l = max(b, c);
		v[co].w = min(b, c);
		co += 1;
		v[co].h = b;
		v[co].l = max(a, c);
		v[co].w = min(a, c);
		co += 1;
		v[co].h = c;
		v[co].l = max(a, b);
		v[co].w = min(a, b);
		co += 1;
	}
 
	sort(v.begin(), v.end(), comp);
 
	ll dp[3 * n];
 
 
	memset(dp, 0, sizeof(dp));
 
	dp[0] = v[0].h;
	ll mx = dp[0];
	//cout << mx << "\n";
	for (ll i = 1; i < v.size(); i++) {
		dp[i] = v[i].h;
		for (ll j = 0; j < i; j++) {
			if (v[j].l < v[i].l && v[j].w < v[i].w) {
				dp[i] = max(dp[i], dp[j] + v[i].h);
			}
			mx = max(mx, dp[i]);
		}
	}
	cout << mx << "\n";
 
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	while (cin >> n && n != 0) {
		solve();
	}
	return 0;
} 