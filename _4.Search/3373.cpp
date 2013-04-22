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
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 100
#define M 10000

int i,j,k,m,n,l,t;
int r[N+10];
char s[N+10];
int g[N+10][6][M+10];

int o(int k){ return (k%m+m)%m; }

void dfs(int i, int j, int k){
	if (i==n || g[i][j][k]!=-1){
		if (g[i][j][k]==-1) g[i][j][k]=-2;
	   	return;
	}
	rep(l, 10){
		if (l==0 && i==0 && n!=1) continue;
		if (s[i]-'0'==l){
			dfs(i+1, j, o(k-r[i]*l));
			if (g[i+1][j][o(k-r[i]*l)]!=-2){
				g[i][j][k]=l; return;
			}
		}
		else if (j){
			dfs(i+1, j-1, o(k-r[i]*l));
			if (g[i+1][j-1][o(k-r[i]*l)]!=-2){
				g[i][j][k]=l; return;
			}
		}
	}
	g[i][j][k]=-2;
}

void out(int i, int j, int k){
	if (i==n){
	   	putchar('\n'); return;
	}
	putchar(g[i][j][k]+'0');
	if (g[i][j][k]==s[i]-'0') out(i+1, j, o(k-r[i]*g[i][j][k]));
	else out(i+1, j-1, o(k-r[i]*g[i][j][k]));
}

void solve(){
	clr(g, -1);
	g[n][0][0]=0;
	repf(j, 0, t){
		dfs(0, j, 0);
		if (g[0][j][0]!=-2){
			out(0, j, 0);
			return; 
		}
	}
}

void init(){
	n=strlen(s);
	r[n-1]=1;
	repd(i, n-2, 0) r[i]=r[i+1]*10%m;
	t=min(5, n);
}

int main(){
	while (~scanf("%s%d", s, &m)){
		init();
		solve();
	}
	return 0;
}


