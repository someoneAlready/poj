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
#define N 9

int i,j,k,m,n,l;
int a[N+10][N+10];
char s[9][10]={"ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};

void guess(){
	rep(i, 9){
		repf(j, i, 8) if (a[j][i]){
			rep(k, 10) swap(a[i][k], a[j][k]);
			break;
		}
		rep(j, 9) if (j!=i && a[j][i]){
			int x=a[i][i], y=a[j][i];
			rep(k, 10) a[j][k]=((a[j][k]*x-a[i][k]*y)%4+4)%4;
		}
	}
	bool first=true;

	rep(i, 9){
		while (a[i][N]%a[i][i]!=0) a[i][N]+=4;
		k=a[i][N]/a[i][i];
		rep(j, k){
		   	if (!first) putchar(' ');
			else first=false;
			printf("%d", i+1);
		}
	}
	putchar('\n');
}

int main(){
	rep(i, 9) rep(j, strlen(s[i])) a[s[i][j]-'A'][i]=1;
	rep(i, 9) scanf("%d", &k), a[i][N]=(-k%4+4)%4;
	guess();
	return 0;
}

