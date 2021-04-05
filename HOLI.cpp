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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//find_by_order() --> returns an iterator to the k-th largest element (counting from zero)
//order_of_key()  --> the number of items in a set that are strictly smaller than our item.
#define  w(t) long long int t;cin>>t;while(t--)
 
ll ans;
vector<pair<ll, ll>> v[100005];
ll dis[100005];
ll vis[100005];
 
ll dfs(ll src, vector<pair<ll, ll>> v[], ll dis[], ll vis[], ll n) {
 
	dis[src] = 1;
	vis[src] = 1;
	for (auto x : v[src]) {
		ll node = x.first;
		ll wt = x.second;
		if (vis[node] == 0) {
			dis[src] += dfs(node, v, dis, vis, n);
			ll nx = dis[node];
			ll ny = n - nx;
			ans += 2 * min(nx, ny) * wt;
		}
	}
	return dis[src];
 
}
void solve() {
 
	ll n;
	cin >> n;
 
	for (ll i = 0; i <= n + 1; i++) {
		v[i].clear();
		dis[i] = 0;
		vis[i] = 0;
	}
 
 
	for (ll i = 0; i < n - 1; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
 
		v[a].pb(mp(b, c));
		v[b].pb(mp(a, c));
	}
	ans = 0;
	dfs(1, v, dis, vis, n);
	cout << ans << "\n";
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll co = 1;
	w(t) {
		cout << "Case " << " " << "#" << co << ":" << " ";
		solve();
		co++;
	}
	return 0;
} 