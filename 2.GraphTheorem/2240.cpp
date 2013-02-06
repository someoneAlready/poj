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
const int N= 30;

struct P{
	int to; double w;
	P(){}
	P(int to, double w):to(to), w(w){}
};

int i,j,k,m,n,l;
double d, dist[N+10];
int in[N+10];
double v[N+10];
char sa[N+10][1000], s[1000], t[1000];

bool gao(vp *a, int e){
	queue<int> q;

	dist[e]=1, q.push(e), v[e]=true, in[e]=1;

	while (!q.empty()){
		int i=q.front();
		rep(k, sz(a[i])){
			P p=a[i][k];
			if (dist[p.to]==-1 || dist[p.to]<dist[i]*p.w){
				dist[p.to]=dist[i]*p.w;
				if (!v[p.to])
					v[p.to]=true, q.push(p.to), in[p.to]++;
				if (in[p.to]>=n) return true;
			}
		}
		v[i]=false, q.pop();
	}
	return false;
}

bool gao(vp *a){
	fill(v+1, v+1+n, false);
	fill(in+1, in+1+n, 0);
	fill(dist+1, dist+1+n, -1);
	repf(i, 1, n) if (dist[i]==-1){
		if (gao(a, i)) return true;
	}
	return false;
}


struct H{
	const static int N=100003;
	int h[N+10];
	H(){memset(h, -1, sizeof(h));}
	int gao(char *s){
		int ret=0, n=strlen(s);
		rep(i, n) ret=(ret*131+s[i])%N;
		return ret;
	}
	int operator[](char *s){
		int k=gao(s);
		while (strcmp(sa[h[k]], s)!=0){
		   	k=(k+1)%N;
		}
		return h[k];
	}
	void gao(char *s, int i){
		int k=gao(s);
		while (h[k]!=-1 && strcmp(sa[h[k]], s)!=0){
		   	k=(k+1)%N;
		}
		h[k]=i;
	}
};

int main(){
	int test=0;
	while (~scanf("%d", &n) && n){
		H h;

		repf(i, 1, n){
			scanf("%s", sa[i]);
			h.gao(sa[i],i);
		}
		vp a[N+10];

		scanf("%d", &m);
		while (m--){
			scanf("%s%lf%s", s, &d, t);
			a[h[s]].pb(P(h[t],d));
		}
		if (gao(a)) printf("Case %d: Yes\n", ++test);
		else printf("Case %d: No\n", ++test);
	}
	return 0;
}


