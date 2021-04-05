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
#define  w(t) long long int t;cin>>t;while(t--)
 
 
vector<vector<ll>> adj;
 
bool dfs(ll src, ll vis[], ll col[], ll clr) {
 
	vis[src] = 1;
	col[src] = clr;
	for (auto x : adj[src]) {
		if (vis[x] == -1) {
			if (dfs(x, vis, col, clr ^ 1) == false) {
				return false;
			}
		}
		else if (col[x] == col[src]) {
			//	cout << x << " " << src << " " << col[src] << " " << col[x] << "adv\n";
			return false;
		}
	}
	return true;
}
 
 
void solve() {
 
	ll n, m;
	cin >> n >> m;
	adj.clear();
	adj.resize(n + 1);
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
 
	ll vis[n + 1], col[n + 1];
	for (ll i = 1; i <= n; i++) {
		vis[i] = -1;
		col[i] = -1;
	}
 
	for (ll i = 1; i <= n; i++) {
		if (vis[i] == -1) {
			bool ans = dfs(i, vis, col, 0);
			if (ans == false) {
				cout << "Suspicious bugs found!" << "\n";
				return;
			}
		}
	}
 
	cout << "No suspicious bugs found!" << "\n";
 
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	ll ct = 0;
 
	w(t) {
		ct++;
		cout << "Scenario #" << ct << ":"<<"\n";
		solve();
	}
	return 0;
} 