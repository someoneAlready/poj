#ifndef _HEAD_H_
#define _HEAD_H_
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define sz(a) ((int)(a).size())
#define SQR(x) ((x)*(x))

using namespace std;

#endif
#define N 1000

double dis(int i, int j, double l);


template<int SZ>
class Prim{
	double d[SZ+10];
	bool done[SZ+10];

public:
	int n;

	double minSpanTree(double l){
		rep(i, n) d[i] = 1e100;
		memset(done, 0, sizeof(done));
		d[0] = 0;

		double ret = 0;

		rep(times, n){
			int i = -1;

			rep(j, n) if (!done[j] && (i==-1 || d[j]<d[i])){
				i = j;
			}

			done[i] = true;
			ret += d[i];

			rep(j, n) if (!done[j]){
				d[j] = min(d[j], dis(i, j, l));
			}
		}

		return ret;
	}
};


int n;
int costMax;
Prim<N> prim;
int x[N+10], y[N+10], z[N+10];
double dist[N+10][N+10];

double eculidDistance(int i, int j){
	return  sqrt(0. + SQR(x[i]-x[j]) + SQR(y[i]-y[j]) );
}

double dis(int i, int j, double l){
	return abs(z[i]-z[j]) - l * dist[i][j];
}

double eps = 1e-7;
double solve(){
	double x = 0.;
	double y = costMax;
	
	while (y-x>eps){
		double l = (x+y)/2;

		prim.n = n;
		double tmp = prim.minSpanTree(l);

		if (tmp>0) x = l+eps;
		else y = l;

	}
	return x;
}

int main(){
	while (~scanf("%d", &n) && n){
		costMax = 0;
		rep(i, n){ 
			scanf("%d%d%d", &x[i], &y[i], &z[i]);
			costMax = max(costMax, z[i]);
		}

		rep(i, n) repf(j, i+1, n-1)
			dist[j][i] = dist[i][j] = eculidDistance(i, j);

		printf("%.3lf\n", solve());
	}
	return 0;
}

