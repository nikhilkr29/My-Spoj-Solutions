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
 
ll n;
ll hir, sal, ter;
 
ll dp[30][300];
 
ll solve(ll req[], ll day, ll worker) {
 
	if (day >= n) {
		return 0;
	}
 
	if (dp[day][worker] != -1) {
		return dp[day][worker];
	}
 
 
	if (day == 0) {
		ll b = req[0] * (sal + hir) + solve(req, day + 1, req[0]);
		return b;
	}
 
 
	ll ex = worker - req[day];
	ll op1 = inf, op2 = inf, op3 = inf, op4 = inf;
	if (ex >= 0) {
		op1 = (sal * worker) + solve(req, day + 1, worker);
 
	}
 
	if (ex < 0) {
		op2 = (abs(ex) * hir) + req[day] * (sal) + solve(req, day + 1, req[day]);
	}
 
	if (ex > 0) {
		for (ll i = 1; i <= ex; i++) {
			ll q = sal * (worker - i) + (i * ter) + solve(req, day + 1, worker - i);
			op3 = min(op3, q);
		}
	}
 
 
	ll ans = min({op1, op2, op3});
	return dp[day][worker] = ans;
}
 
void nk() {
	cin >> hir >> sal >> ter;
 
	ll req[n];
	for (ll i = 0; i < n; i++) {
		cin >> req[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(req, 0, 0) << "\n";
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ll co = 0;
	while (cin >> n && n != 0) {
		co += 1;
		cout << "Case " << co << ", cost = $";
		nk();
	}
	return 0;
} 