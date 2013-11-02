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
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 5
#define M 6

int i,j,k,m,n,l;
int d[5][2]={ 0, 0, 0, -1, 0, 1, -1, 0, 1, 0};
int a[N*M+10][N*M+10];

void guess(){
	rep(i, 30){
		repf(j, i, 29) if (a[j][i]){
			rep(k, 31) swap(a[i][k], a[j][k]);
			break;
		}
		rep(j, 30) if (i!=j && a[j][i]){
			int x=a[i][i], y=a[j][i];
			rep(k, 31) a[j][k]=((a[j][k]*x-a[i][k]*y)%2+2)%2;
		}
	}
	rep(i, 5){
		rep(j, 6){
			if (j) putchar(' ');
			int x=i*6+j;
			printf("%d", a[x][30]/a[x][x]);
		}
		putchar('\n');
	}
}

int main(){
	int tests;
	scanf("%d", &tests);
	repf(test, 1, tests){
		clr(a, 0);
		rep(i, 5) rep(j, 6){
			scanf("%d", &a[i*6+j][5*6]);
			rep(k, 5){
				int x=d[k][0]+i, y=d[k][1]+j;
				if (x>=0 && y>=0 && x<5 && y<6) a[i*6+j][x*6+y]=1;
			}
		}
		printf("PUZZLE #%d\n", test);
		guess();
	}
	return 0;
}

