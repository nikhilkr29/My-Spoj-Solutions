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
 
 
vector<vector<ll>> adj;
 
ll vis[100005];
 
void dfs(ll src, ll par) {
	vis[src] = 1;
 
	for (auto x : adj[src]) {
		if (x != par && vis[x] == -1) {
			dfs(x, src);
		}
	}
}
 
void solve() {
 
	ll n;
	cin >> n;
	adj.clear();
	adj.resize(n);
	memset(vis, -1, sizeof(vis));
	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
 
	ll co = 0;
	for (ll i = 0; i < n; i++) {
		if (vis[i] == -1) {
			co++;
			dfs(i, -1);
		}
	}
	cout << co << "\n";
 
 
 
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