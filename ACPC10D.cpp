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
void nk() {

  ll dp[n][3];
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < 3; j++) {
      cin >> dp[i][j];
    }
  }

  dp[0][2] += dp[0][1];    //First Row me sirf middle element se aa skta hai
  dp[1][0] += dp[0][1];    //Second Row k first element tk sirf First Row k mid element se aa skta hai
  dp[1][1] += min({dp[1][0], dp[0][1], dp[0][2]}); //Second Row k mid element ko 2nd row k first elem or 1st row k second or third elem se aa skta hai
  dp[1][2] += min({dp[1][1], dp[0][1], dp[0][2]}); //Second Row k last elem tk second row k 2nd or first row k mid or last elem se pahuca ja skta hai


  for (ll i = 2; i < n; i++) {
    dp[i][0] += min(dp[i - 1][0], dp[i - 1][1]); //First Elem tk pichle row ka First or Second elem se pahuca ja skta hai
    dp[i][1] += min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i][0]}); //Mid elem tk upr wale k kisi bhi elem ya ussi row k first elem se pahuca ja skta hai
    dp[i][2] += min({dp[i][1], dp[i - 1][1], dp[i - 1][2]}); //Last Elem tk ussi row k mid elem se ya upr wale row k mid or lst elem se pahuca ja skta hai
  }

  cout << dp[n - 1][1] << "\n";  //Cost of Reaching the mid elem of lst row


}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  ll c = 1;
  while (cin >> n && n != 0) {
    cout << c << "." << " ";
    nk();
    c++;
  }
  return 0;
}