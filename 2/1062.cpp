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
#define INF ((int)1e9)
#define N 500

struct P{
	int to, w;
	P(){}
	P(int to, int w):to(to),w(w){}
};

int i,j,k,m,n,l,r;
bool v[N+10];
int dist[N+10], gra[N+10], val[N+10];

int spfa(vp a[]){
	queue<int> q;
	fill(v+1, v+1+n, false);	
	fill(dist+1, dist+1+n, INF);

	q.push(1), v[1]=true, dist[1]=val[1];

	while (!q.empty()){
		int i=q.front(); 
		rep(k, sz(a[i])){
			P j=a[i][k];
			if (gra[j.to]<l || gra[j.to]>r) continue;
			if (abs(gra[1]-gra[j.to])<=m && dist[j.to]>dist[i]-val[i]+j.w+val[j.to]){
				dist[j.to]=dist[i]-val[i]+j.w+val[j.to];
				if (!v[j.to])
					v[j.to]=true, q.push(j.to); 
			}
		}
		v[i]=false; q.pop();
	}
	int ret=INF;
	repf(i, 1, n) ret=min(ret, dist[i]);
	return ret;
}

int main(){
	while (~scanf("%d%d", &m, &n)){
		vp a[n+10];
		repf(i, 1, n){
			scanf("%d%d%d", &val[i], &gra[i], &l);
			while (l--){
				scanf("%d%d", &j, &k);
				a[i].pb(P(j,k));
			}
		}
		int ans=INF;
		for (l=gra[1]-m; l<=gra[1]; ++l){
			r=l+m;
			ans=min(ans, spfa(a));
		}
		cout<<ans<<endl;
	}
	return 0;
}


