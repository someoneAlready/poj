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

template<int SZ>
class Hungray{
	vector<int> a[SZ+10];
	int f[SZ+10], v[SZ+10];
	public:
	int n;

	void clear(){
		rep(i, SZ+10) a[i].clear();
	}

	void add(int i, int j){
		a[i].push_back(j);
	}

	bool find(int i){
		rep(j, sz(a[i])){
			int k=a[i][j];
			if (!v[k]){
				v[k]=true;
				if (!f[k] || find(f[k])){
					f[k]=i;
					return true;
				}
			}
		}
		return false;
	}

	int match(){
		int ret=0;
		memset(f, 0, sizeof(f));
		repf(i, 1, n){
			memset(v, 0, sizeof(v));
			if (find(i)) ret++;
		}
		return ret;
	}

};

#define N 40

int n, m, l;
bool v[N+10][N+10];
int d[4][2] = {-1,0, 1,0, 0,1, 0,-1};
Hungray<N*N> hungray;

bool solve(){
	int tot = n*m - l;
	if (tot%2==1) return false;

	hungray.n = n*m;

	repf(i, 1, n) repf(j, 1, m)
		if (!v[i][j] && (i+j)%2 == 0){
			rep(k, 4){
				int x = i + d[k][0];
				int y = j + d[k][1];

				if (x>=1 && x<=n && y>=1 && y<=m && !v[x][y])
					hungray.add((i-1)*m+j, (x-1)*m+y);
			}

		}

	return hungray.match() == (tot/2);
}

int main(){
	while (~scanf("%d%d%d", &n, &m, &l)){
		memset(v, 0, sizeof(v));
		hungray.clear();

		int x, y;
		rep(i, l){
			scanf("%d%d", &x, &y);
			v[y][x] = 1;
		}
		puts(solve()?"YES":"NO");
	}
}

