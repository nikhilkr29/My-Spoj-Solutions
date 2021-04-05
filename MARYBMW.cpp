#include<bits/stdc++.h>
using namespace std;
#define  vi vector<long long int>
#define  set1 set<long long int>
#define  pb push_back
#define  pob pop_back
#define  map1 map<long long int,long long int>
#define  ll long long int
#define  mp make_pair
#define  inf 1e18+1
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
	return e1.w > e2.w;
}
 
vector<vector<pair1>> g;
 
void solve() {
 
	ll n, m;
	cin >> n >> m;
	v.clear();
	g.resize(n + 1);
	g.clear();
	for (ll i = 1; i <= n; i++) {
		g[i].clear();
	}
 
	par.assign(n + 1, -1);
	for (ll i = 0; i < m; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		v.pb({x, y, z});
	}
	sort(v.begin(), v.end(), comp);
 
	for (auto x : v) {
		if (getp(x.a) != getp(x.b)) {
			unite(x.a, x.b);
			g[x.a].pb({x.b, x.w});
			g[x.b].pb({x.a, x.w});
		}
	}
 
 
	if (getp(1) != getp(n)) {
		cout << "-1" << "\n";
		return;
	}
 
 
	queue<ll> q;
	q.push(1);
 
	vi vis(n + 1, -1);
 
	vi p1(n + 1, -1), c1(n + 1, 0);
 
	vector<pair1> pd;
 
	while (!q.empty()) {
 
		ll src = q.front();
		q.pop();
		vis[src] = 1;
		for (auto x : g[src]) {
			if (vis[x.first] == -1) {
				q.push(x.first);
				p1[x.first] = src;
				c1[x.first] = x.second;
			}
		}
	}
 
	ll p = p1[n];
	ll res = c1[n];
	while (p != 1) {
		if (res == -1) {
			res = c1[p];
		}
 
		res = min(res, c1[p]);
		p = p1[p];
 
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