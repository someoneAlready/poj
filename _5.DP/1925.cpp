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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 5000
#define M 1000000

struct P{
	int x, y;
	void input(){ scanf("%d%d", &x, &y); }
};

int i,j,k,m,n,l;
P a[N+10];
int g[M+10];

int main(){
	int tests;
	scanf("%d", &tests);
	while(tests--){
		scanf("%d", &n);
		repf(i, 1, n) a[i].input();
		int ans=-1;
		clr(g, -1);
		g[a[1].x]=0;
		repf(i, 2, n){
			repf(j, max(a[1].x, (int)ceil(a[i].x-sqrt(a[1].y*(2.*a[i].y-a[1].y))-10)), a[i].x-1) 
				if (g[j]!=-1 && SQR(0ll+a[i].y-a[1].y)+SQR(0ll+a[i].x-j)<=SQR(0ll+a[i].y)){
				if (2*a[i].x-j>=a[n].x){
				   	_checkmin(ans, g[j]+1);
				}
				else _checkmin(g[2*a[i].x-j], g[j]+1);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


