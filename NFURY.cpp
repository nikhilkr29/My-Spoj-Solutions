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
#define  w(t) long long int t;cin>>t;while(t--)
 
ll a[10005];
 
void solve() {
 
	ll n;
	cin >> n;
	cout << a[n] << "\n";
 
 
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
 
	memset(a, 0, sizeof(a));
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	ll co = 0, id = 0;
	for (ll i = 2; i <= 35; i++) {
		a[i * i] = 1;
	}
 
	for (ll i = 4; i <= 1000; i++) {
		if (a[i] == 1) {
			id = i;
		}
		else {
			a[i] = min(1 + a[i - 1], 1 + a[i - id]);
			for (ll j = 1; j < i; j++) {
				a[i] = min(a[i], a[j] + a[i - j]);
			}
 
		}
	}
 
 
 
	w(t) {
		solve();
	}
	return 0;
} 