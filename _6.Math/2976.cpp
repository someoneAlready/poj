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
#define N 1000
#define eps 1e-7
double z;

struct P{
	int x, y;
	bool operator <(const P &p)const{
		return x-y*z>p.x-p.y*z;
	}
};

int i,j,k,m,n,l;
P a[N+10];

double gao(double z){
	::z=z;
	sort(a, a+n);
	double ret=0;
	rep(i, n-m) ret+=a[i].x-a[i].y*z;
	return ret;
}

int main(){
	while (~scanf("%d%d", &n, &m) && n+m){
		rep(i, n) scanf("%d", &a[i].x);
		rep(i, n) scanf("%d", &a[i].y);
		double x=0, y=1;
		while (y-x>eps){
			double z=mid(x, y+eps);
			if (gao(z)<0) y=z-eps;
			else x=z;
		}
		printf("%d\n", (int)round(x*100));
	}
	return 0;
}

