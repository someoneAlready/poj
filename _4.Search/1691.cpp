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
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 15
#define C 20

struct P{
	int x1, y1, x2, y2, c;
	void input(){ scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c); }
	bool operator<(const P&p)const{ return x1<p.x1; }
};

int i,j,k,m,n,l;
P p[N+10];
int a[N+10], v[C+10];
int f[1<<N+2];
vi c;

void dfs(int now){
	if (f[now]!=-1) return;
	rep(i, sz(c)) if (v[c[i]]&now){
		int k=v[c[i]], l=now;
		rep(j, n) if (   (k&(1<<j)) && (l&(1<<j)) ){
			if (!(a[j]&l)) l-=(1<<j);
		}	
		if (l!=now) {
			dfs(l);
			_checkmin(f[now], f[l]+1);
		}

	}
}

int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%d", &n);
		clr(v, 0), c.clear();

		rep(i, n) p[i].input(), v[p[i].c]+=1<<i;
		rep(i, 30) if (v[i]) c.pb(i);

		sort(p, p+n);
		clr(a, 0);
		rep(i, n){
			rep(j, n) if (i!=j && p[i].x1==p[j].x2){
				int y1=max(p[i].y1, p[j].y1), y2=min(p[i].y2, p[j].y2);
				if (y2-y1>0) a[i]+=1<<j;
			}
		}
		clr(f, -1);
		f[0]=0;
		dfs((1<<n)-1);
		cout<<f[(1<<n)-1]<<endl;
	}
	return 0;
}


