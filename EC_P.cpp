#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define  vi vector<long long int>
#define  set1 set<long long int>
#define  pb push_back
#define ins insert
#define  map1 map<long long int,long long int>
#define  ll   long long int
#define  inf INT_MAX
#define  minf INT_MIN
#define setbits(x) __builtin_popcountll(x)
#define pres(x,y) fixed<<setprecision(y)<<x
#define pair1 pair<long long int,long long int>
#define mk(arr,n,type) type *arr=new type[n];
#define mod 1000000007
#define mem memset(t,0,sizeof(t))
#define w(t) long long int t;cin>>t; while(t--)
 
bool comp(pair<ll, ll> p1, pair <ll, ll> p2) {
 
	if (p1.first != p2.first)
		return p1.first < p2.first;
	else
		return p1.second < p2.second;
}
 
void dfs(ll v, ll p, vector<ll> a[], ll vis[], ll tim, ll in[], ll low[], vector<pair<ll, ll>> &boss) {
 
	in[v] = low[v] = tim++;
	vis[v] = 1;
	for (auto child : a[v]) {
 
		if (child == p) {
			continue;
		}
		if (vis[child] == 1) {
			//Back Edge
			low[v] = min(low[v], in[child]);
		}
		else {
 
			//Forward Edge
			dfs(child, v, a, vis, tim, in, low, boss);
			low[v] = min(low[v], low[child]);
			if (low[child] > in[v]) {
 
				if (v <= child)
					boss.pb(make_pair(v, child));
				else
					boss.pb(make_pair(child, v));
 
			}
		}
	}
 
}
void solve() {
 
	ll n, m;
	cin >> n >> m;
	vector<ll> a[n + 1];
	ll j = 0;
	for (ll i = 0; i < m; i++) {
		ll x, y;
		cin >> x >> y;
		a[x].pb(y);
		a[y].pb(x);
		j = x;
	}
 
	ll vis[n + 1], in[n + 1], low[n + 1];
	memset(vis, 0, sizeof(vis));
	memset(in, 0, sizeof(in));
	memset(low, 0, sizeof(low));
 
 
	vector<pair<ll, ll>> boss;
	dfs(j, -1, a, vis, 0, in, low, boss);
 
	ll res = boss.size();
	if (res == 0) {
		cout << "Sin bloqueos" << "\n";
		return;
	}
	sort(boss.begin(), boss.end(), comp);
	cout << res << "\n";
	for (auto x : boss) {
		cout << x.first << " " << x.second << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll con = 1;
	w(t) {
		cout << "Caso #" << con << "\n";
		solve();
		con += 1;
	}
	return 0;
} 