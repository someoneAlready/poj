#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())

#define N 60

struct P{
	int i, k, ret;
	void in(int _i){ i=_i; scanf("%d", &k); }
	bool operator <(const P&p)const{
		return k>p.k;
	}
};

bool cmp(P a, P b){ return a.i<b.i; }

int i,j,k,m,n,l;
P a[N*3+10];
int s[N*3+10];
int now;

bool dfs(int d, int pre){
	if (2*n-pre<n-d) return false;

	k=s[pre]-s[pre+n-d];
	if (now+k<=500*n || s[0]-now-s[n+d]<=500*n) return false;

	if (d==n){
			rep(i, 2*n) if (a[i].ret==0) a[i].ret=2;
			return true;
	}

	repf(i, pre, 2*n-1){
		a[i].ret=1;
		now+=a[i].k;
		if (dfs(d+1, i+1)) return true;
		a[i].ret=0;
		now-=a[i].k;
	}
	return false;
}

int main(){
	scanf("%d", &n);
	rep(i, 3*n) a[i].in(i);
	sort(a, a+3*n);
	rep(i, n) a[i+2*n].ret=0;

	rep(i, 2*n) m+=a[i].k;
	repd(i, 2*n-1, 0) s[i]=s[i+1]+a[i].k;

	dfs(0, 0);

	rep(k, 3)
	rep(i, 3*n) if (a[i].ret==k) printf("%d\n", a[i].i+1);
	return 0;
}
