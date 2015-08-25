#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for(int i=(a); i<=(b); ++i)
#define repd(i, a, b) for(int i=(a); i>=(b); --i)
#define sz(a) ((int)(a).size())

#define N 20
#define DEBUG 0 

template <class T> void _checkmin(T &a, T b){ if (a==-1 || b<a) a = b; }

struct E{
	int i, j, k;
	E(){}
	E(int i, int j, int k):i(i),j(j),k(k){}
	bool operator <(const E &e)const{
		return k<e.k;
	}
};

int m, limit, n, p;
int e[N+10][N+10];
int f[N+10];

int find(int i){
	if (f[i] == i) return i;
	return f[i] = find(f[i]);
}

int solve(){
	int ret = INT_MAX;

	vector<int> x;
	repf(i, 1, n) if (e[p][i] != -1) x.push_back(i);

	vector<E> edge;
	repf(j, 1, n) repf(k, j+1, n)
		if (e[j][k] != -1)
			edge.push_back(E(j, k, e[j][k]));
	sort(edge.begin(), edge.end());

	rep(i, 1<<sz(x)){
		repf(j, 1, n) f[j] = j;

		int tmp = 0, cnt = 0;
		bool flag = false;
		rep(j, sz(x)) if ((1<<j)&i){
			int s = find(p);
			int t = find(x[j]);
			if (s != t){
				f[s] = t;
				tmp += e[p][x[j]];
				++ cnt;

			}
			else{
				flag =true;
				break;
			}
		}

		if (cnt > limit || flag) continue;

		rep(j, sz(edge))
			if (edge[j].i != p && edge[j].j != p){
				int x = find(edge[j].i);
				int y = find(edge[j].j);
				if (x != y){
					f[x] = y;
					tmp += edge[j].k;
					++ cnt;
				}
			}

		if (cnt==n-1) ret = min(ret, tmp);
	}
	return ret;
}

int main(){
	scanf("%d", &m);
	map<string,int> mp;

	memset(e, -1, sizeof(e));

	n = 0;
	rep(xxx, m){
		string s, t;
		int i, j, k;
		cin>>s>>t>>k;

		i = mp[s];
		if (i==0){
			i = ++n;
			mp[s] = i;
		}

		j = mp[t];
		if (j==0){
			j = ++n;
			mp[t] = j;
		}

		_checkmin(e[i][j], k);
		_checkmin(e[j][i], k);
	}

	p = mp[string("Park")];
	scanf("%d", &limit);

	printf("Total miles driven: %d\n", solve());
	return 0;
}
