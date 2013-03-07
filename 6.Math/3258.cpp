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
template <class T> void checkmax(T &t, T x){if (x > t) t = x;}
template <class T> void checkmin(T &t, T x){if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1 || x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1 || x < t) t = x;}
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define fill(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 50000

int i,j,k,m,n,l;
int a[N+10];

int gao(int k, int key){
	int ret=0, w=-1;
	vi v(1,0);
	repf(i, 1, n){
		if (a[i]-v[sz(v)-1]<=k) ret++;
		else _checkmin(w, a[i]-v[sz(v)-1]), v.pb(a[i]);
	}
	repd(i, sz(v)-1, 0){
		if (l-v[i]<=k) ret++;
		else _checkmin(w, l-v[i]);

	}
	return key==0?ret:w;
}

int main(){
	while (~scanf("%d%d%d", &l, &n, &m)){
		repf(i, 1, n) scanf("%d", &a[i]);
		sort(a+1, a+1+n), a[1+n]=l;
		int x=0, y=l;
		repf(i, 1, n+1) checkmin(x, a[i]-a[i-1]);
		while (x<y){
			int z=mid(x, y+1);
			if (gao(z,0)<=m) x=z;
			else y=z-1;
		}
		cout<<gao(x,1)<<endl;
	}
	return 0;
}


