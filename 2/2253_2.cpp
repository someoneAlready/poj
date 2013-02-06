#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <iterator>
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
#define N 2000

struct P{
	int x,y;
	void input(){
		scanf("%d%d", &x, &y);
	}
	int dist(const P& p){
		return SQR(x-p.x)+SQR(y-p.y);
	}
};

int i,j,k,m,n,l;
P a[N+10];
int f[N+10];

struct E{
	int i, j; int d;
	E(int i, int j, double d):i(i),j(j),d(d){}
	bool operator <(const E &e)const {
		return d<e.d;
	}
};

int find(int i){
	if (f[i]==i) return i;
	return f[i]=find(f[i]);
}

int gao(){
	vector<E> e;
	e.clear();
	repf(i, 1, n) repf(j, 1, n)
		e.pb(E(i,j,a[i].dist(a[j])));
	sort(e.begin(), e.end());
	repf(i, 1, n) f[i]=i;
	rep(i, sz(e)){
		f[find(e[i].i)]=find(e[i].j);
		if (find(1)==find(2)) return e[i].d;
	}
}

int main(){
	int test=0;
	while (~scanf("%d", &n) && n){
		repf(i, 1, n) a[i].input();
		printf("Scenario #%d\n", ++test);
		printf("Frog Distance = %.3f\n\n", sqrt((float)gao()));
	}
	return 0;
}


