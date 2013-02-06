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
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define pb push_back
#define sz(a) ((int)(a).size())
#define mid(x, y) ((x+y)/2)
#define fill(a, b) memset(a, b, sizeof(a))
#define N 100

struct P{
	int s; double r, c;
	P(){}
	P(int s, double r, double c):s(s),r(r),c(c){}
};


int i,j,k,m,n,l;
vector<P> a[N+10];
double dist[N+10];
bool vis[N+10];
int s;
double v;

bool gao(){
	fill(vis, 0);
	fill(dist, 0);

	queue<int> q;
	q.push(s);
	dist[s]=v;
	vis[s]=true;
	
	while (!q.empty()){
		int i=q.front();
		rep(k, sz(a[i])){
			P p=a[i][k];
			if (dist[p.s]<p.r*(dist[i]-p.c)){
				dist[p.s]=p.r*(dist[i]-p.c);
				if (!vis[p.s])
					vis[p.s]=true, q.push(p.s);
			}
		}				
		q.pop(), vis[i]=false;
		if (dist[s]>v) return true;
	}
	return false;
}

int main(){
	while (cin>>n>>m>>s>>v){
		repf(i, 1, n) a[i].clear();
		while (m--){
			double r1, c1, r2, c2;
			scanf("%d%d%lf%lf%lf%lf",&i, &j, &r1, &c1, &r2, &c2);
			a[i].pb(P(j,r1,c1)), a[j].pb(P(i,r2,c2));
		}
		if (gao()) puts("YES");
		else puts("NO");
	}
	return 0;
}


