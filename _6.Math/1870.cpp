#include <iostream>
#include <algorithm>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;
#define N 10000
#define M 100

int d[6][2]={1,0, 0,-1, -1, -1, -1,0, 0,1, 1,1};
bool v[M*2+10][M*2+10];

struct P{
	int x, y;
	P(){}
	P(int x, int y):x(x),y(y){}
	P operator + (const P&p)const{ return P(x+p.x, y+p.y); }
	P operator - (const P&p)const{ return P(x-p.x, y-p.y); }
	void mark(int i, int j){
		x = i;
		y = j;
		v[x+M][y+M]=2;
		for (int k=0; k<6; ++k){
			i = x + d[k][0];
			j = y + d[k][1];
			if (v[i+M][j+M]==0) v[i+M][j+M]=1;
		}
	}
	void out(){
		cout << x << ' ' << y << endl;
	}
};

int i,j,k,m,n,l;
P a[N+10];

void init(){
	a[1].mark(0, 0);
	int j = 2, det = 6;
	P bg(1, 0);
	k = 4;
	while (j <= N){
		P p = bg;
		for (int i=0; i<det; ++i){
			a[j+i] = p;
			P q = P(p.x+d[k][0], p.y+d[k][1]);
			while (v[q.x+M][q.y+M]!=1){
				k = (k + 5) % 6;
				q = P(p.x+d[k][0], p.y+d[k][1]);
			}
			p = q;
		}
		for (int i=0; i<det; ++i){
			a[j].mark(a[j].x, a[j].y);
			j++;
		}
		det += 6;
		bg = bg + P(0, -1);
	}
}

int main(){
	init();
	while (~scanf("%d%d", &n, &m) && n+m){
		P det = a[n] - a[m];
		int ret = 0;
		if (det.x * det.y > 0){
			ret = max( abs(det.x), abs(det.y) );
		}
		else 
			ret = abs(det.x) + abs(det.y);
		printf("The distance between cells %d and %d is %d.\n", n, m, ret);
	}
	return 0;
}

