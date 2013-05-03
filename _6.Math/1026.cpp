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
#define N 200

int i,j,k,m,n,l;
int a[N+10][N+10], b[N+10], f[N+10];
char s[N+10];
bool v[N+10];

template <class T>T gcd(T a, T b){
	return b==0?a:gcd(b, a%b);
}

int gao(){
	clr(v, 0);
	int ret=0;
	repf(i, 1, n) if (!v[i]){
		vi vc;
		int j=i, k=0;
		while (!v[j]){
			vc.pb(j);
			v[j]=1; 
			j=b[j];
		}
		_checkmax(ret, sz(vc));
		rep(j, sz(vc)) f[vc[j]]=sz(vc);
	}
	return ret;
}


int main(){
	while (~scanf("%d", &n) && n){
		repf(i, 1, n) scanf("%d", &b[i]), a[0][i]=i;
		l=gao();

		repf(i, 1, l-1) repf(j, 1, n)
			a[i][b[j]]=a[i-1][j];

		while (~scanf("%d", &m) && m){
			getchar();
			clr(s, 0), gets(s);
			while (strlen(s)<n) s[strlen(s)]=' ';

			repf(j, 1, n) 
				putchar(s[ a[ m%f[j] ][j]-1]);
			puts("");
		}
		puts("");
	}
	return 0;
}


