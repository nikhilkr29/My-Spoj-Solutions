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

ll a[205][205];
ll dp[205][205][2]; //The Third column is for whether you are moving left or right
//0 for left and 1 for right


void solve() {

  memset(dp, 0, sizeof(dp));
  memset(a, 0, sizeof(a));

  ll n, m;
  cin >> n >> m;

  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      char x;
      cin >> x;
      if (x == 'T') {
        a[i][j] = 2;
      }
      else if (x == '0') {
        a[i][j] = 1;
      }
      else {
        a[i][j] = 0;
      }
    }
  }

  for (ll i = n; i >= 1; i--) {

    //0 is for left
    if (i % 2 == 0) {
      for (ll j = 1; j <= m; j++) {
        if (a[i][j])
          dp[i][j][0] = max(dp[i + 1][j][1], dp[i][j - 1][0]) + (a[i][j] - 1);
      }
    }
    else {
      //1 is for right
      for (ll j = m; j >= 1; j--) {
        if (a[i][j])
          dp[i][j][1] = max(dp[i + 1][j][0], dp[i][j + 1][1]) + (a[i][j] - 1);
      }
    }
  }
  
  //Kahi pr koi value ho humme toh matlab hai first point pr kya value aaya sab 
  //Chalane k baad woh bhi right face krte hue islie code simple hai or isme bht edge
  //Case consider ni krna pra agr dp[1][1][1] pr jo aaya hoga whi max rhega hmare lie

  //Eg : For the given i/p :
              //T#T
							//TTT
							//T#T

  //The dp matrix looks like this : 
                  //3 0 5 
								  //2 3 4 
								  //1 0 1
  //Although there is 5 in the dp matrix but we dont care cause we only care what is at dp[1][1][1]
 //Kyuki ek valid path se (1,1) se srt krke jo mile whi hmara ans hoga

   
  
  cout << dp[1][1][1] << "\n";




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
