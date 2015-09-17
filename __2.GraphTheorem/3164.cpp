#ifndef _HEAD_H_
#define _HEAD_H_
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define sz(a) ((int)(a).size())
#define SQR(x) ((x)*(x))

using namespace std;

template <class T> void checkmin(T &a, T b){ if (b<a) a=b; }
#endif
#define N 100
#define INF 1e100

int n, m;

struct P{
	double x, y;
	void input(){
		scanf("%lf%lf", &x, &y); 
	}
	inline double dis(const P&p)const{
		return sqrt(SQR(x-p.x)+SQR(y-p.y));
	}
};

struct E{
	int i, j;
	double len;
	E(int i, int j, double len):i(i),j(j),len(len){};
};

P a[N+10];
vector<E> e;

int vis[N+10];
int id[N+10];
int pre[N+10];
double preLen[N+10];


double solve(){
	int root = 1;

	double ret = 0.;
	while (1){
		memset(pre, -1, sizeof(pre));
		repf(i, 1, n) preLen[i] = INF;

		rep(i, sz(e)){
			if (e[i].i!=e[i].j && e[i].len < preLen[e[i].j]){
				preLen[e[i].j] = e[i].len;
				pre[e[i].j] = e[i].i;
			}
		}

		pre[root] = -1;
		preLen[root] = 0.;


		repf(i, 1, n){
			if (i!=root && pre[i]==-1) return -1.;
		   	ret += preLen[i];
		}

		memset(id, 0, sizeof(id));
		memset(vis, 0, sizeof(vis));
		int k = 0;
		bool loopExist = 0;

		repf(i, 1, n){
			int j = i;
			while (j!=-1 && !vis[j]){
				vis[j] = i;
				j = pre[j];
			}
			
			if (j!=-1 && vis[j]==i){
				loopExist = 1;

				++k;
				while (id[j]==0){
					id[j] = k;
					j = pre[j];
				}
			}
		}

		if (!loopExist) return ret;

		repf(i, 1, n) if (!id[i]) id[i] = ++k;

		rep(i, sz(e)){
			e[i].len -= preLen[e[i].j];
			e[i].i = id[e[i].i];
			e[i].j = id[e[i].j];
		}

		root = id[root];
		n = k;
	}
}

int main(){
	while (scanf("%d%d", &n, &m)!=EOF){
		repf(i, 1, n) a[i].input();

		e.clear();
		repf(i, 1, m){
			int j, k;
			scanf("%d%d", &j, &k);
			if (j==k || k==1) continue;
			e.push_back(E(j, k, a[j].dis(a[k])));
		}

		double ans = solve();
		if (ans<0.0) 
			puts("poor snoopy");
		else
			printf("%.2lf\n", ans);
	}

	return 0;
}
