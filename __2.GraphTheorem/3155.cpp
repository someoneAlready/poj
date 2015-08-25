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
#define INF 1e10
#define N 100
#define M 1000

int n, m;

template <class T>
int sgn(T d, T eps=.5/n/n){ 
	return d<-eps?-1:d>eps; 
}


template<class T>
struct e_t{ 
	int to, rev;
	T cap;
	e_t(int to, T cap, int rev):to(to), cap(cap), rev(rev){
//		printf("%.3lf\n", cap);
	}
};

template<int SZ, class T>
class Dinic{
	public:
		vector<e_t<T> > a[SZ+10];
		int lev[SZ+10], done[SZ+10];	
		int s, t;

		void getCut(int i, vector<bool> & v){
			v[i] = true;
			for (size_t k=0; k<a[i].size(); ++k){
				if ( sgn(a[i][k].cap) == 0)
					continue;
				int j  = a[i][k].to;
				if (v[j] == false)
					getCut(j, v);

			}
		}

		bool levelize(){
			queue<int> q; 
			memset(lev, -1, sizeof(lev));
			q.push(s), lev[s]=0;
			while (!q.empty()){
				int i=q.front(); q.pop();
				rep(k, sz(a[i])){
					e_t<T> e=a[i][k];
					if ( sgn(e.cap)==0  || lev[e.to]!=-1) continue;
					lev[e.to] = lev[i] + 1;
					q.push(e.to);
				}
			}
			return lev[t]!=-1;
		}

		T augment(int v, T f){
			if (v==t || sgn(f)==0 ) return f;
			for (; done[v] <sz(a[v]); ++done[v]){
				e_t<T> &e = a[v][done[v]];
				if (lev[e.to] < lev[v] || sgn(e.cap)==0 ) continue;
				T t = augment(e.to, min(f, e.cap));
				if (sgn(t)>0 ){
					e.cap -= t;
					a[e.to][e.rev].cap += t;
					return t;
				}
			}
			return 0.;
		}

		void clear(){
			rep(i, SZ) a[i].clear();
		}

		void add(int i, int j, T c){
			a[i].push_back(e_t<T>(j, c, sz(a[j])));
			a[j].push_back(e_t<T>(i, 0., sz(a[i])-1));
		}

		T maxFlow(){
			T tot=0, tmp;
			while (levelize()){
				memset(done, 0, sizeof(done));
				while (true){
					tmp = augment(s, INF);
					if (sgn(tmp) == 0) break;
					tot += tmp;
				}
			}
			return tot;
		}
};

typedef Dinic<M+N+100,double> MyDinic;

void buildGraph(int n, int m, 
		vector<pair<int,int> > &edge, 
		MyDinic &dinic,
		double mid){

	dinic.clear();
	dinic.s = 0;
	dinic.t = n+m+1;
	for (int i = 1; i <= n; ++i) 
		dinic.add(i, dinic.t, mid);

	for (size_t i=0; i<edge.size(); ++i){
		dinic.add(dinic.s, n+1+i, 1.);
		dinic.add(n+1+i, edge[i].first, INF);
		dinic.add(n+1+i, edge[i].second, INF);
	}
}

struct Plan{
	int nn, mm;
	double ratio;
	vector<int> ans;
	Plan(vector<bool> & v, vector<pair<int,int> >&edge){
		nn = mm = 0;
		
		for (int i=1; i<=n; ++i) if (v[i])
			++nn, ans.push_back(i);

		for (size_t i=0; i<edge.size(); ++i)
			if (v[edge[i].first] && v[edge[i].second])
				++mm;
		if (nn) ratio = 1.*mm/nn;
	}
	Plan(){
		nn = mm = 0;
	}
};

void solve(int n, int m, vector<pair<int,int> > &edge){
	static MyDinic dinic;
	double x = 0., y = (double) m;

	Plan bestPlan;

	while (y-x>=1./n/n){
		double mid = (x+y)/2;

		buildGraph(n, m, edge, dinic, mid);
		double cut = dinic.maxFlow();
		double result = m - cut;

		if (sgn(result)>0) x = mid ;
		else y = mid;

		vector<bool> v(n+m+2, false);
		dinic.getCut(dinic.s, v);
		Plan plan(v, edge);
		
		if (bestPlan.nn == 0 || (plan.nn!=0 && plan.ratio > bestPlan.ratio) ){
			bestPlan = plan;
		}
	}

	printf("%d\n", (int) bestPlan.ans.size());
	for (size_t i = 0; i<bestPlan.ans.size(); ++i)
		printf("%d\n", bestPlan.ans[i]);
}

int main(){
	while (~scanf("%d%d", &n, &m)){
		if (m==0){
			printf("1\n1\n");
			continue;
		}
		vector<pair<int, int> > edge;
		for (int i=0; i<m; ++i){
			int j, k;
			scanf("%d%d", &j, &k);
			edge.push_back(make_pair(j, k));
		}

		solve(n, m, edge);	
	}
	return 0;
}

