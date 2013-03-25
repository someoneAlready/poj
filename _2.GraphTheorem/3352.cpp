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
#define N 1000
int i,j,k,m,n,l;
vi a[N+10];
int pre[N+10], low[N+10];
int dfs_clock;
bool b[N+10][N+10];

void dfs(int i, int fa){
	pre[i]=low[i]=++dfs_clock;
	rep(k, sz(a[i])){
		int j=a[i][k];
		if (j==fa) continue;
		if (!pre[j]){
			dfs(j, i), checkmin(low[i], low[j]);
			if (low[j]>pre[i]) b[i][j]=b[j][i]=1;
		}
		else if (pre[j]<pre[i]) 
			checkmin(low[i], pre[j]);
	}
}

void find_bridge(){
	clr(b, 0), clr(pre, 0), dfs_clock=0;
	dfs(1, -1);
}

int bcc_cnt;
int bccno[N+10];
vi c[N+10];

void dfs2(int i, int fa){
	bccno[i]=bcc_cnt;
	rep(k, sz(a[i])){
		int j=a[i][k];
		if (j==fa || b[i][j]) continue;
		if (!bccno[j]) dfs2(j, i);
	}
}

int dfs3(int i, int fa){
	pre[i]=1;
	int ret=0, child=0;
	rep(k, sz(c[i])){
		int j=c[i][k];
		if (j==fa) continue;
		if (!pre[j]) ret+=dfs3(j, i), child++;
	}
	if (!ret) ret++;
	if (fa<0 && child==1) ret++;
	return ret;
}

int solve(){
	clr(bccno, 0), bcc_cnt=0;
	repf(i, 1, n) if (!bccno[i])
		bcc_cnt++, dfs2(i, -1);
	repf(i, 1, bcc_cnt) c[i].clear();
	repf(i, 1, n) rep(k, sz(a[i])){
		int ii=bccno[i], jj=bccno[a[i][k]];
		if (ii!=jj) c[ii].pb(jj), c[jj].pb(ii);
	}
	clr(pre, 0);
	int ret=dfs3(1, -1);
	return ret==1?0:ret/2+ret%2;
}

int main(){
	while (~scanf("%d%d", &n, &m)){
		repf(i, 1, n) a[i].clear();
		while (m--)
		   	scanf("%d%d", &i, &j), a[i].pb(j), a[j].pb(i);
		find_bridge();
		printf("%d\n", solve());
	}
	return 0;
}


