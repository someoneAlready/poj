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
#define N 100

int i,j,k,m,n,l;
bool a[N+10][N+10];
int s[N+10][N+10];
int x, y;

int main(){
	while (~scanf("%d", &l) && l){
		scanf("%d%d", &n, &m);
		clr(a, 0);
		while (l--)
			scanf("%d%d", &i, &j), a[i][j]=1;
		int x, y;
		scanf("%d%d", &x, &y);
		repf(i, 1, n) repf(j, 1, m) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(a[i][j]?1:0);
		int ans=0;
		repf(i, x, n) repf(j, y, m) checkmax(ans, s[i][j]-s[i-x][j]-s[i][j-y]+s[i-x][j-y]);
		cout<<ans<<endl;


	}
	return 0;
}


