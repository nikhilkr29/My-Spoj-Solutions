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
 
ll n;
 
 
void solve() {
 
	stack<ll> s, p;
 
	bool res = true;
 
	ll a[n + 1];
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
 
	ll cur = 1;
	for (ll i = 1; i <= n; i++) {
		if (a[i] == cur) {
			s.push(a[i]);
			cur++;
		}
		else {
			p.push(a[i]);
		}
 
		while (p.empty() == false && p.top() == cur) {
			p.pop();
			s.push(cur);
			cur++;
		}
	}
 
 
 
	if (s.size() == n)
		cout << "yes" << "\n";
	else
		cout << "no" << "\n";
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	while (cin >> n && n != 0) {
		solve();
	}
	return 0;
} 