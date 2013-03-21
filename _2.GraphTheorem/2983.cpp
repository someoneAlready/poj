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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 1000

int m,n,l;
char s[100];
struct E{
	int to, w;
	E(int to, int w):to(to), w(w){}
};
vector<E> a[N+10];
bool v[N+10];
int deg[N+10], inQ[N+10], dist[N+10];

bool spfa(int ss, int n){
	queue<int> q; clr(v, 0), clr(inQ, 0);
	fill(dist, dist+1+n, INT_MAX);

	q.push(ss), v[ss]=1, dist[ss]=0;

	while (!q.empty()){
		int i=q.front();
		v[i]=false, q.pop();			//注意要在之前标记v[i]为false，不如i更新了就无法如队列了。。。-_-|||
		rep(k, sz(a[i])){
			int j=a[i][k].to, w=a[i][k].w;	

			if (dist[i]+w<dist[j]){
				dist[j]=dist[i]+w;
				if (!v[j]){
					v[j]=true, q.push(j), inQ[j]++;
					if (inQ[j]>n) return false;
				}
			}
		}
	}
	return true;
}

int main(){
	while (~scanf("%d%d", &n, &m)){
		repf(i, 0, n) a[i].clear();
		repf(i, 1, n) a[0].pb(E(i,0));
		while (m--){
			scanf("%s" ,s);
			if (s[0]=='P'){
				int i, j, k;
				scanf("%d%d%d", &i, &j, &k);
				a[i].pb(E(j, -k)), a[j].pb(E(i, k));
			}
			else if (s[0]=='V'){
				int i, j;
				scanf("%d%d", &i, &j);
				a[i].pb(E(j, -1));
			}
		}
		if (spfa(0, n)) puts("Reliable");
		else puts("Unreliable");
	}
	return 0;
}


