#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){if (x > t) t = x;}
template <class T> void checkmin(T &t, T x){if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1 || x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1 || x < t) t = x;}
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define fill(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N (1<<16)
ll m, n;
vi prm;
bool v[N+10];
int a[N+10];
map<ll,int> mp;

void gao(ll n, int e){
	rep(i, sz(prm)){
		while (n%prm[i]==0)
			n/=prm[i], a[i]+=e;
	}
	if (n!=1) mp[n]+=e;
}

int main(){
	repf(i, 2, N) if (!v[i]){
		prm.pb(i);
		repf(j, 2, N/i) v[i*j]=1;
	}
	while (cin>>n>>m && n+m){
		fill(a, 0), mp.clear();
		if (m>n) swap(m,n);
		repf(i, 1, m){
			gao(i+n, 1);
			gao(i, -1);
		}	
		ll ret=1;
		rep(i, sz(prm)) rep(j, a[i]) ret*=prm[i];
		foreach(it, mp) rep(j, it->second) ret*=it->first;
		cout<<ret<<endl;
	}
	return 0;
}


