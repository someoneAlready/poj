#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>
#include <cctype>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back
#define INF (INT_MAX/100)

#define N 50

struct e_t {int to, cap, rev, cost;};

template <int SZ>
class MCMF{
public:
	vector<e_t> a[SZ*5+10];
	int f[SZ*5+10], c[SZ*5+10];
	bool inQ[SZ*5+10];
	e_t *e[SZ*5+10];
	int s, t;

	void clear(){ rep(i, t+1) a[i].clear(); }
	void add(int i, int j, int c, int cost){
		a[i].pb((e_t){j, c, sz(a[j]), cost});
		a[j].pb((e_t){i, 0, sz(a[i])-1, -cost});
	}
	bool bellmanFord(int &flow, int &cost){
		queue<int> q;
		clr(f, 0), clr(c, -1), clr(inQ, 0);

		q.push(s), f[s]=INF, c[s]=0, inQ[s]=1;
		while (sz(q)){
			int i=q.front(); q.pop(), inQ[i]=0;
			rep(k, sz(a[i])){
				e_t & ei = a[i][k];
				if (ei.cap && c[ei.to]<c[i]+ei.cost){
					f[ei.to]=min(f[i], ei.cap);
					c[ei.to]=c[i]+ei.cost;
					e[ei.to]=&ei;
					if (!inQ[ei.to]) inQ[ei.to]=1, q.push(ei.to);
				}
			}
		}
		if (c[t]==-1) return false;
		flow+=f[t], cost+=c[t]*f[t];
		int i=t;
		while (i!=s){
			e[i]->cap-=f[t];
			a[i][e[i]->rev].cap+=f[t];
			i=a[i][e[i]->rev].to;
		}
		return true;
	}
	void minCost(int &flow, int &cost){
		while (bellmanFord(flow, cost));
	}
};

int i,j,k,m,n,l;
int a[N+10][N+10];
MCMF<N*(N+1)+10> mcmf;

int main(){
	scanf("%d%d", &n, &m);
	rep(i, n) rep(j, n) scanf("%d", &a[i][j]);
	
	mcmf.s=n*n*2, mcmf.t=mcmf.s+1;
	mcmf.clear();

	mcmf.add(mcmf.s, 0, m, 0);
	mcmf.add(((n-1)*n+(n-1))*2+1, mcmf.t, m, 0);

	rep(i, n) rep(j, n){
		k=i*n+j;
		mcmf.add(k*2, k*2+1, 1, a[i][j]);
		mcmf.add(k*2, k*2+1, INF, 0);
		if (j!=n-1) mcmf.add(k*2+1, (k+1)*2, INF, 0);
		if (i!=n-1) mcmf.add(k*2+1, (k+n)*2, INF, 0);
	}
	int x=0, y=0;
	mcmf.minCost(x, y);
	cout<<y<<endl;
	return 0;
}
