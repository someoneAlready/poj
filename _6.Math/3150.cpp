#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>
#include <cctype>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back

#define N 500

int i,j,k,m,n,l,d;
int o[N+10];

struct Mat{
	ll a[N+10];
	Mat(){ clr(a, 0); }
	Mat operator *(const Mat& mt)const{
		Mat ret;
		rep(j, n) rep(k, n){
			ret.a[j]+=a[k]*mt.a[(j-k+n)%n];
		}
		rep(j, n) ret.a[j]%=m;
		return ret;
	}
};

Mat a, x;

int main(){
	while (~scanf("%d%d%d%d", &n, &m, &d, &k)){
		rep(i, n) scanf("%d", &o[i]);

		rep(j, n) a.a[j]=(j==0?1:0);
		rep(j, n) x.a[j]=(min(j, n-j)<=d?1:0);
		
		while (k){
			if (k&1) a=a*x;
			x=x*x;
			k>>=1;
		}
		rep(i, n){
			if (i) putchar(' ');
			ll ret=0;
			rep(j, n) ret+=o[j]*a.a[(i-j+n)%n];
			printf("%d", (int)(ret%m));
		}
		putchar('\n');
	}
	return 0;
}
