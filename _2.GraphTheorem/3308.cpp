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
template <class T> void checkmax(T &t, T x){if (x > t) t = x;}
template <class T> void checkmin(T &t, T x){if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1 || x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1 || x < t) t = x;}
#define INF (1e20)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 50*5
#define eps 1e-8
int sgn(double d){ return d<-eps?-1:d>eps; }

struct e_t {
	int to, rev;
	double cap;
	e_t(int to, double cap, int rev):to(to),cap(cap),rev(rev){}
};

vector<e_t> a[N+10];
int lev[N+10], done[N+10];
int i,j,k,m,n,l;
int s, t;

void add(int i, int j, double c){
        a[i].pb(e_t(j, c, sz(a[j])));
        a[j].pb(e_t(i, 0, sz(a[i])-1));
}
 
bool levelize(){
        clr(lev, -1);
        queue<int> q;
        lev[s]=0;
        q.push(s);
        while (!q.empty()){
                int i=q.front(); q.pop();
                rep(k, sz(a[i])){
                        e_t e=a[i][k];
                        if (sgn(e.cap)<=0 || lev[e.to]!=-1) continue;
                        lev[e.to] = lev[i]+1;
                        q.push(e.to);
                }
        }
        return lev[t]!=-1;
}
 
double augmemt(int v, double f){
        if (v==t || sgn(f)<=0) return f;
        for (; done[v] < sz(a[v]); done[v]++){
                e_t &e = a[v][done[v]];
                if (lev[e.to] <= lev[v] || sgn(e.cap)<=0) continue;
                double t = augmemt(e.to, min(f, e.cap));
                if (sgn(t)>0){
                        e.cap-=t;
                        a[e.to][e.rev].cap+=t;
                        return t;
                }
        }
        return 0;
}
 
double max_flow(){
        double f=0, t;
        while (levelize()){
                clr(done ,0);
                while (t=augmemt(s, INF))
                         f+=t;
        }
        return f;
}


int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%d%d%d", &n, &m, &l);
		s=n*2+m*2, t=s+1;
		rep(i, t+1) a[i].clear();
		double k;
		rep(i, n) scanf("%lf", &k), add(i*2, i*2+1, log(k));
		rep(i, m) scanf("%lf", &k), add(n*2+i*2, n*2+i*2+1, log(k));
		while (l--) scanf("%d%d", &i, &j), i--, j--, add(i*2+1, n*2+j*2, INF);		
		
		rep(i, n) add(s, i*2, INF);
		rep(i, m) add(n*2+i*2+1, t, INF);
		printf("%.4f\n", exp(max_flow()));

	}
	return 0;
}

