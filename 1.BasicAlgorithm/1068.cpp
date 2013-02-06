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
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define pb push_back
#define sz(a) ((int)(a).size())
#define mid(x, y) ((x+y)/2)
#define fill(a, b) memset(a, b, sizeof(a))
#define N 20

int i,j,k,m,n,l;
int test;
int a[N+10];

int main(){
	scanf("%d", &test);
	while (test--){
		scanf("%d", &n);
		vector<int> v;
		repf(i, 1, n){
			scanf("%d", &a[i]);
			rep(j, a[i]-a[i-1]) v.pb(0);
			v.pb(1);
		}
		vi ans;
		rep(i, sz(v)) if (v[i]==1){
			int k=1, tot=1;
			repd(j, i-1, 0)
				if (v[j]==1) k++, tot++;
				else{
					k--;
					if (k==0) break;
				}
			ans.pb(tot);
		}	
		rep(i, sz(ans)){
			if (i) putchar(' ');
			printf("%d", ans[i]);
		}
		putchar('\n');
	}
	return 0;
}


