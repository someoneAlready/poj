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
#define N 100

int i,j,k,m,n,l;
char s[N+10];
int a[N+10][N+10];

typedef ll T;
T exgcd(T a, T b, T &x, T &y){
	if (b==0) return x=1, y=0, a;
	T ret=exgcd(b, a%b, x, y), t=x;
	x=y, y=t-a/b*y;
	return ret;
}

struct C{
	static int M;
	T x;
	C(T _x){x=(_x%M+M)%M;}
	T anti()const{
		T _x, _y;
		exgcd(x, M, _x, _y);
		return C(_x).x; 
	}
	C operator +(const C &c)const{ return C(x+c.x); }
	C operator -(const C &c)const{ return C(x-c.x); }
	C operator *(const C &c)const{ return C(x*c.x); }
	C operator /(const C &c)const{ return C(x*c.anti()); }
};

int C::M=0;

void guess(){
	rep(i, n){
		repf(j, i, n-1) if (a[j][i]){
			rep(k, n+1) swap(a[i][k], a[j][k]);
			break;
		}
		rep(j, n) if (j!=i && a[j][i]){
			int x=a[i][i], y=a[j][i];
			rep(k, n+1) a[j][k]=((a[j][k]*x-a[i][k]*y)%m+m)%m;
		}
	}

	C::M=m;
	rep(i, n){
		if (i) putchar(' ');
		printf("%d", (C(a[i][n])/C(a[i][i])).x);
	}
	putchar('\n');
}


int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%d%s", &m, s);
		n=strlen(s);
		rep(i, n){
			a[i][n]=(s[i]=='*'?0:s[i]-'a'+1);
			int k=1;
			rep(j, n) a[i][j]=k, k=k*(i+1)%m;
		}
		guess();
	}
	return 0;
}
