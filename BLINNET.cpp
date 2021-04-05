#include<bits/stdc++.h>
using namespace std;
#define  vi vector<long long int>
#define  set1 set<long long int>
#define  pb push_back
#define  pob pop_back
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
 
struct edge {
 
	ll a, b, w;
};
 
vector<edge> v;
vector<ll> par;
 
 
ll getp(ll x) {
	if (par[x] == -1) {
		return x;
	}
	return par[x] = getp(par[x]);
}
 
void unite(ll x, ll y) {
	x = getp(x);
	y = getp(y);
	par[x] = y;
}
 
 
 
bool comp(edge e1, edge e2) {
	return e1.w < e2.w;
}
 
 
 
void solve() {
 
	ll n;
	cin >> n;
 
	v.clear();
	par.clear();
 
	par.assign(n + 1, -1);
 
	for (ll i = 1; i <= n; i++) {
		string s;
		cin >> s;
		ll p;
		cin >> p;
		for (ll j = 0; j < p; j++) {
			ll x, y;
			cin >> x >> y;
			v.pb({i, x, y});
		}
	}
 
 
 
 
 
	sort(v.begin(), v.end(), comp);
 
 
 
	ll res = 0;
 
 
	for (auto x : v) {
		ll f = x.a;
		ll s = x.b;
 
		if (getp(f) != getp(s)) {
			res += x.w;
			//cout << x.a << " " << x.b << "\n";
			unite(x.a, x.b);
		}
	}
 
	cout << res << "\n";
 
 
 
 
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