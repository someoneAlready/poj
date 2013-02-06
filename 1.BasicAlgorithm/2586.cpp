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
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define pb push_back
#define sz(a) ((int)(a).size())
#define mid(x, y) ((x+y)/2)
#define fill(a, b) memset(a, b, sizeof(a))

#define N 12

int i,j,k,m,n,l;
int a[N+10];
int s, d;

int main(){
	while (~scanf("%d%d", &s, &d)){
		rep(i, 12) a[i]=s;
		rep(i, 8){
			k=0;
			repf(j, i, i+4) k+=a[j];
			repd(j, i+4, i) if (a[j]>0 && k>0)
				a[j]=-d, k=k-s-d;
		}
		int ans=0;
		rep(i, 12) ans+=a[i];
		if (ans<0) puts("Deficit");
		else printf("%d\n", ans);
	}
	return 0;
}


