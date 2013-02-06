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
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 2000

struct P{
	int i,j,k;
	P(){}
	P(int i, int j, int k):i(i),j(j),k(k){}
	bool operator <(const P& p)const{
		return k<p.k;
	}
};

int i,j,k,m,n,l;
char a[N+10][10];
int f[N+10];

int diff(char *s, char *t){
	int n=strlen(s), ret=0;
	rep(i, n) if (s[i]!=t[i]) ret++;
	return ret;
}

int find(int i){
	if (f[i]==i) return i;
	return f[i]=find(f[i]);
}

P e[N*N+10];

int main(){
	while (~scanf("%d", &n) && n){
		rep(i, n) scanf("%s", a[i]);
		rep(i, n) rep(j, n) e[i*n+j]=P(i,j,diff(a[i],a[j]));
		m=n*n;
		sort(e, e+m);
		int ans=0, tot=0;
		rep(i, n) f[i]=i;
		rep(i, m){
			int j=find(e[i].i), k=find(e[i].j);
			if (j!=k){
				f[j]=k,	ans+=e[i].k, tot++;
				if (tot==n-1) break;
			}
		}
		printf("The highest possible quality is 1/%d.\n", ans);

	}
	return 0;
}


