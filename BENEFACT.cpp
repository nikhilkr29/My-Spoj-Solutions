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
 
vector <pair<ll, ll> > adj[100000];
 
 
 
ll mx = -1, node = 1;
 
void dfs(ll src, ll dis, ll vis[]) {
 
	vis[src] = 1;
 
	if (mx < dis) {
		mx = dis;
		node = src;
	}
 
	for (auto x : adj[src]) {
		ll f = x.first;
		ll s = x.second;
		if (vis[f] == -1) {
			dfs(f, dis + s, vis);
		}
	}
 
}
 
void solve() {
 
	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		adj[i].clear();
	}
 
	ll vis[n + 1];
	memset(vis, -1, sizeof(vis));
 
	for (ll i = 0; i < n - 1; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		adj[a].pb({b, c});
		adj[b].pb({a, c});
	}
 
	node = 0, mx = -1;
 
	dfs(1, 0, vis);
 
 
	memset(vis, -1, sizeof(vis));
 
	mx = -1;
 
	dfs(node, 0, vis);
 
	cout << mx << "\n";
 
 
 
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