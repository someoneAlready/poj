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
#define N 2000

struct P{
	int x,y;
	void input(){
		scanf("%d%d", &x, &y);
	}
	double dist(const P& p){
		return sqrt(1.*SQR(x-p.x)+SQR(y-p.y));
	}
};

int i,j,k,m,n,l;
P a[N+10];
double dist[N+10];
bool v[N+10];

void spfa(){
	fill(dist+1, dist+1+n, 1e9);
	queue<int> q;
	fill(v+1, v+1+n, false);

	q.push(1), v[1]=true, dist[1]=0;
	
	while (!q.empty()){
		int i=q.front();
		repf(j, 1, n) if (j!=i){
			double k=max(a[i].dist(a[j]), dist[i]);
			if (dist[j]>k){
				dist[j]=k;
				if (!v[j])
					v[j]=true, q.push(j);
			}
		}
		v[i]=false, q.pop();
	}
}

int main(){
	int test=0;
	while (~scanf("%d", &n) && n){
		repf(i, 1, n) a[i].input();
		spfa();
		printf("Scenario #%d\n", ++test);
		printf("Frog Distance = %.3f\n\n", dist[2]);
	}
	return 0;
}


