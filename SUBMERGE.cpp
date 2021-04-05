#include<bits/stdc++.h>
using namespace std;
#define  vi vector<long long int>
#define  set1 set<long long int>
#define  pb push_back
#define  map1 map<long long int,long long int>
#define  ll long long
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
#define  w(t) long long int t;t=1;while(t)
 
ll n, m;
 
vector<vector<ll>> adj;
ll in[100005], low[1000005], timer = 0;
set1 s;
void dfs(ll src, ll par, ll vis[]) {
 
	vis[src] = 1;
	ll children = 0;
	in[src] = low[src] = timer++;
	for (auto x : adj[src]) {
		if (vis[x] == false) {
			dfs(x, src, vis);
			children++;
			//cout << low[x] << " " << in[src] << " " << par << "\n";
			if (low[x] >= in[src] && par != -1) {
				s.ins(src);
			}
			low[src] = min(low[src], low[x]);
		}
		else if (x != par) {
			//This is Back Edge
			low[src] = min(in[x], low[src]);
		}
	}
	if (children > 1 && par == -1) {
		s.ins(src);
	}
 
 
}
 
void solve() {
	s.clear();
	adj.clear();
	adj.resize(n + 1);
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	ll vis[n + 1];
	memset(vis, 0, sizeof(vis));
	timer = 0;
	for (ll i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			dfs(i, -1, vis);
		}
	}
	cout << s.size() << "\n";
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
 
	w(t) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		solve();
	}
	return 0;
} 