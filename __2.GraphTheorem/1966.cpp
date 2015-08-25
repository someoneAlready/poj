#include <algorithm>
#include <iostream>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define sz(a) ((int)(a).size())

#define N 50
#define M (N*N)
#define INF 1000000

int n, m;
int x[M+10], y[M+10];
bool v[N+10][N+10];



#include <vector>
#include <queue>

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
		a[i].push_back(e_t(j, c, sz(a[j])));
		a[j].push_back(e_t(i, 0, sz(a[i])-1));
	}

	int maxFlow(){
		int tot=0, tmp;
		while (levelize()){
			memset(done, 0, sizeof(done));
			while ( (tmp = augment(s, INF)) )
				tot += tmp;
		}
		return tot;
	}
};

Dinic<2*N+20> dinicA, dinic;

int solve(){
	if (n<=1) return n;
	int ret = n;
	rep(i, n)
		repf(j, i+1, n-1) if (!v[i][j]){
			dinic = dinicA;
			dinic.add(dinic.s, i*2, INF);
			dinic.add(i*2, i*2+1, INF);

			dinic.add(j*2, j*2+1, INF);
			dinic.add(j*2+1, dinic.t, INF);

			int flow = dinic.maxFlow();
			ret = min(ret, flow);
		}
	return ret;
}

void input(int &x, int &y){
	char c=getchar();
	int tmp = 0;
	while (true){
		if (isdigit(c))
			tmp = tmp*10+(c-'0');
		else if (c==','){
			x=tmp;
			tmp=0;
		} else if (c==')'){
			y=tmp;
			break;
		}
		c=getchar();
	}
}

int main(){
	while (~scanf("%d%d", &n, &m)){
		int x, y;
		memset(v, 0, sizeof(v));

		dinicA.clear();
		rep(i, n) dinicA.add(i*2, i*2+1, 1);

		rep(i, m){
			int x, y;
			input(x, y);
			v[x][y]=v[y][x]=1;
			dinicA.add(x*2+1, y*2, INF);
			dinicA.add(y*2+1, x*2, INF);
		}
		dinicA.s = 2*n;
		dinicA.t = 2*n+1;

		printf("%d\n", solve());

	}
	return 0;
}
