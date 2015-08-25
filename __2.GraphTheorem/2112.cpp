#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define sz(a) ((int)(a).size())
#define pb push_back
#define INF 1000000

#define N 300

int a[N+10][N+10];
int n, m, l;

template <class T> 
void  _checkmin(T &a, T b){ if (a==-1 || b<a) a=b; }

void floyd(){
	repf(k, 1, n+m)
		repf(i, 1, n+m) if (a[i][k] != -1)
			repf(j, 1, n+m) if (a[k][j] != -1){
				_checkmin(a[i][j], a[i][k]+a[k][j]);
			}
}


struct e_t{ 
	int to, cap, rev;
	e_t(int to, int cap, int rev):to(to), cap(cap), rev(rev){}
};

template<int SZ>
class Dinic{
public:
	vector<e_t> a[SZ+10];
	int lev[SZ+10], done[SZ+10];	
	int s, t;

	bool levelize(){
		queue<int> q;
		memset(lev, -1, sizeof(lev));
		q.push(s), lev[s]=0;
		while (!q.empty()){
			int i=q.front(); q.pop();
			rep(k, sz(a[i])){
				e_t e=a[i][k];
				if (!e.cap || lev[e.to]!=-1) continue;
				lev[e.to] = lev[i] + 1;
				q.push(e.to);
			}
		}
		return lev[t]!=-1;
	}

	int augment(int v, int f){
		if (v==t || !f) return f;
		for (; done[v] <sz(a[v]); ++done[v]){
			e_t &e = a[v][done[v]];
			if (lev[e.to] < lev[v] || !e.cap) continue;
			int t = augment(e.to, min(f, e.cap));
			if (t){
				e.cap -= t;
				a[e.to][e.rev].cap += t;
				return t;
			}
		}
		return 0;
	}

	void clear(){
		rep(i, SZ) a[i].clear();
	}

	void add(int i, int j, int c){
		a[i].pb(e_t(j, c, sz(a[j])));
		a[j].pb(e_t(i, 0, sz(a[i])-1));
	}

	int maxFlow(){
		int tot=0, tmp=0;
		while (levelize()){
			memset(done, 0, sizeof(done));
			while ((tmp = augment(s, INF)))
				tot += tmp;
		}
		return tot;
	}
};


Dinic<N+10> dinic;

bool check(int mid){
	dinic.clear();
	dinic.s = 0;
	dinic.t = n+m+1;
	repf(i, 1, n) dinic.add(dinic.s, i, l);
	repf(i, n+1, n+m) dinic.add(i, dinic.t, 1);
	repf(i, 1, n)
		repf(j, n+1, n+m) 
			if (a[i][j]!=-1 && a[i][j]<=mid)
				dinic.add(i, j, 1);

	int flow = dinic.maxFlow();
	return flow==m;
}

int solve(){
	int x = INT_MAX;
	int y = 0;

	repf(i, 1, n)
		repf(j, n+1, n+m) 
			if (a[i][j]!=-1){
				x=min(x, a[i][j]);
				y=max(y, a[i][j]);
			}

	while (x!=y){
		int mid = (x+y)/2;
		if (check(mid)) y = mid;
		else x=mid+1;
	}

	return x;
}

int main(){
	while(~scanf("%d%d%d", &n, &m, &l)){
		repf(i, 1, n+m)
			repf(j, 1, n+m){
				scanf("%d", &a[i][j]);
				if (i!=j && a[i][j]==0) a[i][j]=-1;
			}
		floyd();
		
		printf("%d\n", solve());
	}
	return 0;
}
