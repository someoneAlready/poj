#ifndef _HEAD_H_
#define _HEAD_H_
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

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

#endif
#define N 1000
#define M 500
#define INF 1000000


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

char s[100000];
vector<int> a[N+10];
Dinic<N+M+10> dinic;
int n, m;

vector<int> getVec(char *s){
	vector<int> ret;
	int len = strlen(s);
	int tmp = 0;
	bool flag = 0;
	rep(i, len+1){
		if (i<len && isdigit(s[i])){
			tmp = tmp*10 + s[i] - '0';
			flag = 1;
		}
		else if (flag){
			ret.push_back(tmp);
			flag = 0;
			tmp = 0;
		}
	}
	return ret;
}

int solve(){
	dinic.s = n+m;
	dinic.t = n+m+1;

	int x = 1;
	int y = n;
	while (x!=y){
		int z = (x+y)/2;

		dinic.clear();
		rep(i, n){
		   	dinic.add(dinic.s, i, 1);
			rep(j, sz(a[i]))
				dinic.add(i, n+a[i][j], 1);
		}
		rep(i, m)
			dinic.add(i+n, dinic.t, z);

		if (dinic.maxFlow()==n) y = z;
		else x = z+1;
	}
	return x;
}

int main(){
	while (~scanf("%d%d", &n, &m) && (n+m) ){
		rep(i, n){
			scanf("%s", s);
			gets(s);
			a[i] = getVec(s);
		}
		
		printf("%d\n", solve());
	}
	return 0;
}
