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
typedef map<int,int> mii;
typedef long long ll;
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define fill(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 50
#define P 10

int i,j,k,m,n,l,p;

struct X{
	int ip[P], op[P], q;
	void input(){
		scanf("%d", &q);
		rep(i, p) scanf("%d", &ip[i]);
		rep(i, p) scanf("%d", &op[i]);
	}
};

struct e_t{ 
	int to, cap, rev;
	e_t(int to, int cap, int rev):to(to), cap(cap), rev(rev){}
};

template<int SZ>
class MaxFlow{
	vector<e_t> a[SZ+10];
	int lev[SZ+10], done[SZ+10];	
	int s, t;

	bool levelize(){
		queue<int> q; fill(lev, -1);
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

public:
	void init(int ss, int tt){
		s=ss, t=tt;
		rep(i, SZ) a[i].clear();
	}
	void add(int i, int j, int c){
		a[i].pb(e_t(j, c, sz(a[j])));
		a[j].pb(e_t(i, 0, sz(a[i])-1));
	}
	int maxFlow(){
		int tot=0, tmp;
		while (levelize()){
			fill(done, 0);
			while (tmp = augment(s, INF))
				tot += tmp;
		}
		return tot;
	}
	void flow(){
		vector<e_t> v;
		rep(i, n){
			int x=i*2;
			rep(k, sz(a[x])){
				e_t e = a[x][k];
				if (e.to!=i*2+1 && e.to !=t && e.cap && e.to!=s)
					v.pb(e_t(e.to/2+1, x/2+1, e.cap));
				
			}
		}
		cout<<sz(v)<<endl;
		rep(i, sz(v)){
			printf("%d %d %d\n", v[i].to, v[i].cap, v[i].rev);
		}
	}
};

X x[N+10];
MaxFlow<N*4> G;

int main(){
	while (~scanf("%d%d", &p, &n)){
		rep(i, n) x[i].input();

		int s=2*n, t=2*n+1;
		G.init(s, t);
		rep(i, n) G.add(i*2, i*2+1, x[i].q);	
		rep(i, n) rep(j, n) if (i!=j){
			bool ok=true;
			rep(k, p) if ((x[i].op[k] && !x[j].ip[k]) || (!x[i].op[k] && x[j].ip[k]==1)){
				ok=false; break;
			}
			if (ok){
			   	G.add(i*2+1, j*2, INF);
			}
		}
		
		rep(i, n){
			int ip=0, op=0;
			rep(k, p){
				if (x[i].ip[k]==1) ip++;
				op+=x[i].op[k];
			}
			if (ip==0) G.add(s, i*2, INF);
			if (op==p) G.add(i*2+1, t, INF);
		}
		cout<<G.maxFlow()<<' ';

		G.flow();
	}
	return 0;
}


