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
 
 
vector<ll> par;
vector<edge> v;
 
bool cmp(edge e1, edge e2) {
	return e1.w < e2.w;
}
 
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
 
void solve() {
 
	par.clear();
	v.clear();
	ll p;
	cin >> p;
	ll n, m;
	cin >> n >> m;
	par.assign(n + 1, -1);
	v.resize(m);
	for (ll i = 0; i < m; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		v[i].a = x, v[i].b = y, v[i].w = z;
	}
	sort(v.begin(), v.end(), cmp);
 
	ll res = 0;
	for (ll i = 0; i < m; i++) {
		if (getp(v[i].a) != getp(v[i].b)) {
			unite(v[i].a, v[i].b);
			res += v[i].w;
		}
	}
	cout << res*p << "\n";
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