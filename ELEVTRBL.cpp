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
#define  w(t) long long int t;t=1;while(t--)
 
 
void solve() {
 
	ll f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
 
	vector<vector<ll>> adj;
	adj.resize(f + 1);
 
	for (ll i = 1; i <= f; i++) {
		if (i + u <= f) {
			adj[i].pb(i + u);
		}
		if (i - d >= 1) {
			adj[i].pb(i - d);
		}
	}
 
 
	queue<ll> q;
	ll dis[f + 1];
	memset(dis, -1, sizeof(dis));
 
	dis[s] = 0;
	q.push(s);
 
	while (!q.empty() && dis[g] == -1) {
 
		ll node = q.front();
		q.pop();
		for (auto x : adj[node]) {
			if (dis[x] == -1) {
				dis[x] = dis[node] + 1;
				q.push(x);
			}
		}
 
	}
 
	if (dis[g] == -1) {
		cout << "use the stairs" << "\n";
		return;
	}
	cout << dis[g] << "\n";
 
 
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