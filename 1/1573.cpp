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
#define N 10

int i,j,k,m,n,l;

struct P{
	int x,y;
	P(){}
	P(int x,int y):x(x),y(y){}
	P operator +(const P p){
		return P(x+p.x,y+p.y);
	}
};

const P dir[4]={P(-1,0),P(0,-1),P(1,0),P(0,1)};
		//N W S E
int a[N+10][N+10], g[N+10][N+10];

int main(){
	while (~scanf("%d%d%d", &n, &m, &l) && n+m+l){
		fill(a, -1);
		repf(i, 1, n) repf(j, 1, m){
			char ch=getchar();
			while (strchr("NESW", ch)==NULL) ch=getchar();
			if (ch=='N') g[i][j]=0;
			else if (ch=='W') g[i][j]=1;
			else if (ch=='S') g[i][j]=2;
			else g[i][j]=3;
		}
		P p(1, l);
		for (int step=0; ;step++){
			if (p.x<1 || p.y<1 || p.x>n || p.y>m){
				printf("%d step(s) to exit\n", step); break;
			}
			else if (a[p.x][p.y]!=-1){
				printf("%d step(s) before a loop of %d step(s)\n", 
						a[p.x][p.y] ,step-a[p.x][p.y]); 
				break;
			}
			a[p.x][p.y]=step;
			p=p+dir[g[p.x][p.y]];
		}
	}
	return 0;
}


