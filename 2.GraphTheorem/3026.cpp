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
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 50

int X, Y;
char a[N+10][N+10];

struct P{
	int x,y,w;
	P(){}
	P(int x, int y):x(x),y(y){}
	P(int x, int y, int w):x(x),y(y),w(w){}
	bool ok(){
		if (x>=0 && y>=0 && x<X && y<Y && a[x][y]!='#') return true;
		return false;
	}
	P operator +(const P& p){
		return P(x+p.x, y+p.y);
	}
	bool operator <(const P& p)const{
		return w<p.w;
	}
};

P dir[4]={P(-1,0),P(1,0),P(0,-1),P(0,1)};	//Up Down Left Right

int i,j,k,m,n,l;
int dist[N+10][N+10];

void gao(int k,vp &e, vp &V){
	memset(dist, -1, sizeof(dist));
	queue<P> q;

	P v=V[k];
	dist[v.x][v.y]=0, q.push(v);

	while (!q.empty()){
		P v=q.front();
		rep(i, 4){
			P p=dir[i]+v;
			if (p.ok() && dist[p.x][p.y]==-1){
				dist[p.x][p.y]=dist[v.x][v.y]+1;
				q.push(p);
			}
		}
		q.pop();
	}

	rep(i, sz(V)) e.pb(P(k, i, dist[V[i].x][V[i].y]));
}

struct UFS{
	const static int M=100;
	int f[M+10];
	UFS(){rep(i, M+10) f[i]=i;}
	int find(int i){
		if (f[i]==i) return i;
		return f[i]=find(f[i]);
	}
	void unions(int i, int j){
		f[find(i)]=find(j);
	}
				
};

char s[1000];

int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		vp v;
		scanf("%d%d\n", &Y, &X);
		rep(i, X){
			gets(s);
			while (strlen(s)==0) gets(s);
		   	rep(j, Y){
				a[i][j]=s[j];
				if (s[j]=='A' || s[j]=='S'){
				   	v.pb(P(i,j));
				}
			}
		}
		vector<P> e;
		int n=sz(v);
		rep(i, sz(v)) gao(i, e, v);

		sort(e.begin(), e.end());

		UFS ufs;
		int ans=0, tot=0;
		rep(i, sz(e)){

				if (tot>=n-1) break;
			int x=ufs.find(e[i].x), y=ufs.find(e[i].y);
			if (x!=y){
				ufs.unions(x,y), tot++, ans+=e[i].w;
			}
		}
		cout<<ans<<endl;

	}
	return 0;
}


