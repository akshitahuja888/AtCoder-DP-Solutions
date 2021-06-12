#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define ppb 			pop_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define M               1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
#define ld				long double
#define nline 			"\n"
#define all(x) 			(x).begin(), (x).end()
// memset(matrix, 0, sizeof(matrix));

// for debug
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


inline int mod(int x) {return (x % M + M) % M;}
inline int add(int a, int b) {return mod(mod(a) + mod(b));}
inline int sub(int a, int b) {return mod(mod(a) - mod(b) + M);}
inline int mul(int a, int b) {return mod(mod(a) * mod(b));}
inline int power(int a, int p) {int r = 1; while (p) { if (p & 1) r = mul(r, a); a = mul(a, a); p >>= 1; } return r;}
inline int modInv(int a) {return power(a, M - 2);}
inline int divi(int a, int b) {return mul(a, modInv(b));}
inline int fact(int a) {int r = 1; while (a) { r = mul(r, a); a--; } return r;}
inline int ncr(int n, int r) {return mul(mul(fact(n), modInv(fact(n - r))), modInv(fact(r)));}
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b);}
inline int ceil(int x, int y) {if (x % y == 0) {return x / y;} return x / y + 1;}

const int N = 1e5 + 5;
int n;
vi a;
vi b;
vi c;
vector<vector<int> > dp(N, vector<int> (3, -1));

void solve()
{
	cin >> n;
	a.resize(n);
	b.resize(n);
	c.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}

	dp[0][0] = a[0];
	dp[0][1] = b[0];
	dp[0][2] = c[0];

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = a[i] + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = b[i] + max(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = c[i] + max(dp[i - 1][0], dp[i - 1][1]);
	}

	cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("debug.txt", "w", stderr);
#endif

	solve();
	return 0;
}