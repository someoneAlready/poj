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

#define S 100
char s[S+10], t[S+10];

Dinic<1000> dinic;
map<string, int> str2Id;
int idx = 1;

int getId(char *s){
	string st(s);
	int ret = str2Id[st];
	if (ret == 0){
		ret = ++idx;
		str2Id[st] = ret;
	}
	return ret;
}

int main(){
	int n, m, l;
	dinic.s = 0;
	dinic.t = 1;

	scanf("%d", &n);
	rep(i, n){
		scanf("%s", s);
		int k = getId(s);
		dinic.add(dinic.s, k, 1);
	}
	scanf("%d", &m);
	rep(i, m){
		scanf("%s %s", s, t);
		int k = getId(t);
		dinic.add(k, dinic.t, 1);	
	}
	scanf("%d", &l);
	rep(i, l){
		scanf("%s %s", s, t);
		int j = getId(s);
		int k = getId(t);
		dinic.add(k, j, INF);
	}
	printf("%d\n", m - dinic.maxFlow());
	return 0;
}
