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
 
struct edge
{
	ll a, b, w;
 
};
 
 
ll id;
 
vector<edge> v;
vi par;
unordered_set<ll> s;
 
bool comp(edge e1, edge e2) {
 
	if (e1.a == e2.a && e1.b == e2.b) {
		return e1.w <= e2.w;
	}
 
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
 
ll find_set(ll x) {
	if (x == par[x])
		return x;
	return find_set(par[x]);
}
 
 
void solve() {
 
	ll n, m;
	cin >> n >> m;
	s.clear();
 
	par.clear();
	par.assign(n + 1, -1);
	v.clear();
	ll res = 0;
 
	set1 d;
 
 
	for (ll i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		if (x == 1) {
			id = i;
			s.ins(i);
		}
		else {
			d.ins(i);
		}
	}
 
 
	for (auto x : s) {
		if (x != id) {
			v.pb({id, x, 0});
		}
	}
 
	for (ll i = 0; i < m; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		v.pb({x, y, z});
	}
	if (s.size() == n) {
		cout << 0 << "\n";
		return;
	}
 
	if (s.size() == 0) {
		cout << "impossible" << "\n";
		return;
	}
 
	sort(v.begin(), v.end(), comp);
 
 
 
	for (auto x : v) {
		if (getp(x.a) != getp(x.b)) {
			unite(x.a, x.b);
			res += x.w;
		}
	}
 
	set1 f;
	for (ll i = 1; i <= n; i++) {
		f.ins(getp(i));
	}
 
	if (f.size() != 1) {
		cout << "impossible" << "\n";
		return;
 
	}
 
	/**/
 
 
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