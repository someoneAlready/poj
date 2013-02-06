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
#define vp vector<P>

#define N 500

struct P{
	int to, w;
	P(){}
	P(int to, int w):to(to),w(w){}
};

int i,j,k,m,n,l,w;
bool v[N+10];
int dist[N+10], in[N+10];

bool spfa(vp a[]){
	queue<int> q;
	fill(v+1, v+1+n, false);	
	fill(in+1, in+1+n, 0);
	fill(dist+1, dist+1+n, (int)1e8);

	q.push(1), v[1]=true, dist[1]=0, in[1]=1;

	while (!q.empty()){
		int i=q.front(); 
		rep(k, sz(a[i])){
			P j=a[i][k];
			if (dist[j.to]>dist[i]+j.w){
				dist[j.to]=dist[i]+j.w;
				if (!v[j.to]){
					v[j.to]=true, q.push(j.to), in[j.to]++;
					if (in[j.to]==n-1) return true;
				}
			}
		}
		v[i]=false; q.pop();
	}
	return false;
}

int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%d%d%d", &n, &m, &w);
		vp a[n+10];

		while (m--){
			scanf("%d%d%d", &i, &j, &k);
			a[i].pb(P(j,k)), a[j].pb(P(i,k));
		}
		while (w--){
			scanf("%d%d%d", &i, &j, &k);
			a[i].pb(P(j,-k));
		}

		if (spfa(a)) puts("YES");
		else puts("NO");
	}
	return 0;
}


