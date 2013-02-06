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
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define pb push_back
#define sz(a) ((int)(a).size())
#define mid(x, y) ((x+y)/2)
#define fill(a, b) memset(a, b, sizeof(a))
#define N 100

char s[N];
int g[N+10][N+10];

struct R{
	int x, y, d;
	R(){}
	R(int x, int y):x(x),y(y){}
	R(int x, int y, int d):x(x),y(y),d(d){}
	void input(int i){
		scanf("%d%d%s", &x, &y, s);
		if (s[0]=='N') d=0;
		else if (s[0]=='W') d=1;
		else if (s[0]=='S') d=2;
		else d=3;
		g[x][y]=i;
	}
	R operator +(const R &r){
		return R(x+r.x,y+r.y,d);
	}
};

R dir[4]={R(0,1),R(-1,0),R(0,-1),R(1,0)};
		//N W S E

int i,j,k,m,n,l;
R a[N+10];
int A, B;

int main(){
	int test; 
	scanf("%d", &test);
	while (test--){
		fill(g, 0);

		scanf("%d%d", &A, &B);
		scanf("%d%d", &n, &m);
		repf(i, 1, n) a[i].input(i);

		bool gao=true;
		while (m--){
			scanf("%d%s%d", &i, s, &k);
			if (gao){
				if (s[0]=='L')
					a[i].d=(a[i].d+k)%4;
				else if (s[0]=='R')
					a[i].d=(a[i].d-k+4*k)%4;
				else{
					while (k--){
						g[a[i].x][a[i].y]=0;
						a[i]=a[i]+dir[a[i].d];
						if (a[i].x==0 || a[i].y==0 || a[i].x>A || a[i].y>B){
							printf("Robot %d crashes into the wall\n", i), gao=false;
							break;
						}
						else if (g[a[i].x][a[i].y]){
							printf("Robot %d crashes into robot %d\n", i, g[a[i].x][a[i].y]), gao=false;
							break;
						}
						g[a[i].x][a[i].y]=i;
					}
				}
			}
		}
		if (gao) puts("OK");
	}
	return 0;
}


