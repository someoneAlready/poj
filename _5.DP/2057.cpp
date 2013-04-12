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
int fa[N+10];
bool isW[N+10];
vi a[N+10];
int leaf[N+10], re[N+10], f[N+10][2];

bool cmp(int i, int j){
	return leaf[j]*(re[i]+2)<leaf[i]*(re[j]+2);
}

void dfs(int i){
	if (sz(a[i])==0){
		re[i]=f[i][0]=f[i][1]=0, leaf[i]=1;
		return;
	}
	
	vi b;
	rep(k, sz(a[i])){
		int j=a[i][k];
		dfs(j), leaf[i]+=leaf[j];
		b.pb(j);
	}

	sort(all(b), cmp);
	f[i][0]=f[i][1]=re[i]=0;
	rep(k, sz(b)){
		int j=b[k];
		f[i][0]+=leaf[j]*(1+re[i])+f[j][0];
		re[i]+=2+re[j];	
	}

	if (isW[i]) re[i]=0;
}

int main(){
	while (~scanf("%d", &n) && n){
		repf(i, 1, n) a[i].clear();
		clr(isW, 0), clr(leaf, 0);

		repf(i, 1, n){
			scanf("%d", &fa[i]);
		    if (fa[i]>0) a[fa[i]].pb(i);
			char ch=getchar();
			while (ch!='Y' && ch!='N') ch=getchar();
			isW[i]=(ch=='Y');
		}
		dfs(1);
		printf("%.4f\n", 1.*f[1][0]/leaf[1]);
	}
	return 0;
}


