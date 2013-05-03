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
#define N 300
#define eps 1e-8

int i,j,k,m,n,l;
double a[N+10][N+10];

void Guess(int n, int m){
	rep(i, n){
		repf(j, i, m-1) if (fabs(a[j][i])>eps){
			repf(k, i, n) swap(a[i][k], a[j][k]);
			break;
		}
		if (fabs(a[i][i])<eps) continue;
		rep(j, m) if (i!=j & fabs(a[j][i])>eps){
			double det = a[j][i]/a[i][i];
			repf(k, i, n) a[j][k]-=a[i][k]*det;
		}
	}

	rep(i, n){
		if (fabs(a[i][i]<eps)){
			if (fabs(a[i][n])>eps){
				// 无解
			}
			else{
				//很多解
			}
		}
		else{
			a[i][n]/=a[i][i];
			if (fabs(a[i][n])<eps) a[i][n]=0;
		}
	}
}

char sConst[][10]={"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
char s[10], t[10];
int gao(char *s){
	rep(i, 7) if (strcmp(sConst[i], s)==0) return i;
}

int main(){
	while (~scanf("%d%d", &n, &m) && n+m){
		clr(a, 0);
		rep(i, m){
			scanf("%d%s%s", &k, s, t);
			a[i][n]=((gao(t)-gao(s)+1)%7+7)%7;
			cout<<a[i][n]<<endl;
			while (k--) scanf("%d", &j), a[i][j]++, a[i][j]%=7;
		}
	//	Guess(n, m);
	}
	return 0;
}


