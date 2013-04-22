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
#define N 10

struct e_t{
	int to, c, pi, ri;
	e_t(int to, int c, int pi, int ri):to(to),c(c),pi(pi),ri(ri){}
};

int i,j,k,m,n,l,c,p,r;
int ans;
vector<e_t> a[N+10];
int f[1<<N+2][N+10];

void dfs(int i, int k, int pay){
	if (f[k][i]!=-1 && f[k][i]<=pay) return;
	_checkmin(f[k][i], pay);
	if (i==n){
	   _checkmin(ans, pay);	return;
	}
	rep(j, sz(a[i])){
		e_t &e=a[i][j];
		dfs(e.to, k|(1<<e.to), pay+( (k&(1<<e.c))?e.pi:e.ri));
	}

}

int main(){
	while (~scanf("%d%d", &n, &m)){
		repf(i, 1, n) a[i].clear();
		clr(f, -1);
		while (m--){
			scanf("%d%d%d%d%d", &i, &j, &c, &p, &r);
			a[i].pb(e_t(j, c, p, r));
		}	
		ans=-1;
		dfs(1, 2, 0);
		printf(ans==-1?"impossible\n":"%d\n",ans);
	}
	return 0;
}


