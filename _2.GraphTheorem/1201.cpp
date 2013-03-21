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
#define fill(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 60000

struct P{
	int x, y, c;
	void input(){ scanf("%d%d%d", &x, &y, &c); }
};
struct E{
	int to, w;
	E(int to ,int w):to(to), w(w){}
};
	
int i,j,k,m,n,l;
P p[N+10];
vector<E> a[N+10];
int dist[N+10];
bool v[N+10];
int x, y;

int spfa(){
	queue<int> q;
	fill(dist, -1), fill(v, 0);

	dist[x]=0, q.push(x), v[x]=true;
	while (!q.empty()){
		int i=q.front(); 
		rep(j, sz(a[i])){
			int to=a[i][j].to, w=a[i][j].w;
			if (dist[to]<dist[i]+w){
				dist[to]=dist[i]+w;
				if (!v[to])
					v[to]=true, q.push(to);
			}
		}
		repf(j, x, y) cout<<dist[j]<<' ';
		cout<<endl;
		v[i]=false, q.pop();
	}
	return dist[y];
}

int main(){
//	while (~scanf("%d", &n)){
	scanf("%d", &n);
		x=INT_MAX, y=INT_MIN;
		rep(i, n) p[i].input(), checkmin(x, p[i].x), checkmax(y, p[i].y);
		y++;

		repf(i, x, y) a[i].clear(), a[i].pb(E(i+1, 0));
		rep(i, n) a[p[i].x].pb(E(p[i].y+1, p[i].c));
		printf("%d\n", spfa());
//	}
	return 0;
}


