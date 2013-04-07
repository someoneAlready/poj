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
#define N 8
#define M 15

int i,j,k,m,n,l;
int a[N+1][N+1], sum[N+1][N+1];
int s[N+1][N+1][N+1][N+1];
double f[M+10][N+1][N+1][N+1][N+1];

int main(){
	while (~scanf("%d", &n)){
		repf(i, 1, N) repf(j, 1, N) scanf("%d", &a[i][j]);
		repf(i, 1, N) repf(j, 1, N) sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];

		double _x=1.*sum[N][N]/n;

		repf(i, 1, N) repf(j, 1, N) repf(x, i, N) repf(y, j, N)
			s[i][j][x][y]=sum[x][y]-sum[i-1][y]-sum[x][j-1]+sum[i-1][j-1],
			f[1][i][j][x][y]=SQR(s[i][j][x][y]-_x);


		repf(I, 2, n){
			repf(i, 1, N) repf(j, 1, N) repf(x, i, N) repf(y, j, N){
				f[I][i][j][x][y]=INT_MAX;
				repf(xi, i, x-1)
					checkmin(f[I][i][j][x][y], f[I-1][i][j][xi][y]+SQR(s[xi+1][j][x][y]-_x)),
					checkmin(f[I][i][j][x][y], SQR(s[i][j][xi][y]-_x)+f[I-1][xi+1][j][x][y]);
				repf(yi, j, y-1)
					checkmin(f[I][i][j][x][y], f[I-1][i][j][x][yi]+SQR(s[i][yi+1][x][y]-_x)),
					checkmin(f[I][i][j][x][y], SQR(s[i][j][x][yi]-_x)+f[I-1][i][yi+1][x][y]);
			}
		}
		printf("%.3f\n", sqrt(f[n][1][1][N][N]/n));
	}
	return 0;
}


