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
#define  w(t) long long int t;t=1;while(t--)
 
vector<vector<ll>> adj;
 
void dfs(ll src,ll vis[]){
	vis[src]=1;
	for(auto x:adj[src]){
		if(vis[x]==0){
			dfs(x,vis);
		}
	}
}
 
 
void solve() {
 
	ll n,m;
	cin>>n>>m;
 
	adj.resize(n+1);
	for(ll i=0;i<m;i++){
		ll a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
 
	if(m!=n-1){
		cout<<"NO"<<"\n";
		return;
	}
 
 
	ll co=0;
	ll vis[n+1];
	memset(vis,0,sizeof(vis));
 
	for(ll i=1;i<=n;i++){
		if(vis[i]==0){
			dfs(i,vis);
			co++;
		}
	}
 
	if(co==1){
		cout<<"YES"<<"\n";
		return;
	}
	cout<<"NO"<<"\n";
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
 
	w(t) {
		solve();
	}
	return 0;
}