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
#define M 30
#define N 300

template <class T> void _checkmin(T &a, T b){ if (a==-1 || b<a) a=b; }

template <int SZ>
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


int a[M+10][M+10];
int n, m;
Hungray<N> hungray;
int p[N+10], t[N+10], d[N+10];

void floyd(){
	repf(k, 1, m)
		repf(i, 1, m)  if (a[i][k]!=-1)
			repf(j, 1, m) if (a[k][j]!=-1)
				_checkmin(a[i][j], a[i][k] + a[k][j]);
}

int main(){
	while (~scanf("%d%d", &m, &n) && (n+m)){
		repf(i, 1, m) repf(j, 1, m) scanf("%d", &a[i][j]);
		floyd();
		hungray.clear();
		hungray.n = n;
		
		repf(i, 1, n) scanf("%d%d%d", &p[i], &t[i], &d[i]);

		repf(i, 1, n) repf(j, 1, n) if (i != j){
			if (a[p[i]][p[j]] != -1 && t[j] >= t[i]+d[i]+a[p[i]][p[j]] )
				hungray.add(i, j);
		}

		printf("%d\n", n - hungray.match());
	}
	return 0;
}

