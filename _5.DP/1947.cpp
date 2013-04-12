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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 150

int i,j,k,m,n,l;
vi a[N+10];
int sum[N+10];
int ans;
int f[N+10][N+10];

void dfs(int i, int fa){
	sum[i]=1;
	rep(k, sz(a[i])) if (a[i][k]!=fa){
		int j=a[i][k]; dfs(j, i), sum[i]+=sum[j];
	}
	clr(f[i], -1);
	f[i][0]=0;
	f[i][sum[i]]=fa==0?0:1;

	rep(k, sz(a[i])) if (a[i][k]!=fa){
		int j=a[i][k];
		repd(r, sum[i]-1, 0)
			repf(l, 1, min(r, sum[j])) if (f[j][l]!=-1 && f[i][r-l]!=-1)
				_checkmin(f[i][r], f[j][l]+f[i][r-l]);
	}
	if (sum[i]>=m && f[i][sum[i]-m]!=-1){
//		cout<<sum[i]<<' '<<m<<' '<<f[i][sum[i]-m]<<endl;
		checkmin(ans, f[i][sum[i]-m]+(fa==0?0:1));
	}
}

int main(){
	while (~scanf("%d%d", &n, &m)){
		repf(i, 1, n) a[i].clear();
		rep(xx, n-1){
			scanf("%d%d", &i, &j);
			a[i].pb(j), a[j].pb(i);
		}
		ans=INT_MAX;
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}


