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
#define N 7

int i,j,k,m,n,l;
double a[(1<<N)+10][(1<<N)+10];
double f[N+10][(1<<N)+10];

int main(){
	while (~scanf("%d", &n) && n!=-1){
		rep(i, 1<<n) rep(j, 1<<n) scanf("%lf", &a[i][j]);
		rep(j, 1<<n) f[0][j]=1;
		repf(i, 1, n) rep(j, 1<<n){
			f[i][j]=0;
			rep(k, 1<<n) if (k/(1<<i-1)!=j/(1<<i-1) && k/(1<<i)==j/(1<<i))
				f[i][j]+=f[i-1][k]*a[j][k];
			f[i][j]*=f[i-1][j];
		}
		int ans=0;
		rep(j, 1<<n) if (f[n][j]>f[n][ans]) ans=j;
		cout<<ans+1<<endl;
	}
	return 0;
}

