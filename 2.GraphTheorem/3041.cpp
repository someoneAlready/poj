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
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define pb push_back
#define fill(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 500

int i,j,k,m,n,l;
vi a[N+10];
int f[N+10], v[N+10];

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

int main(){
	while (~scanf("%d%d", &n, &m)){
		repf(i, 1, n) a[i].clear();
		while (m--){
			scanf("%d%d", &i, &j);
			a[i].pb(j);
		}
		int ans=0;
		fill(f, 0);
		repf(i, 1, n){
			fill(v, 0);
			if (find(i)) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}


